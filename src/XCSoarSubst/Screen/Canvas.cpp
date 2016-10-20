/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2016 Peter F Bradshaw
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include "Canvas.hpp"
#include "Features.hpp"
#include "Screen/Custom/Cache.hpp"
#include "Screen/Bitmap.hpp"
#include "Screen/Util.hpp"
#include "Util/AllocatedArray.hpp"
#include "Util/Macros.hpp"

#ifdef UNICODE
#include "Util/ConvertString.hpp"
#endif

#ifndef NDEBUG
#include "Util/UTF8.hpp"
#endif

#include <assert.h>
#include <math.h>
#include <iostream>
#include <Qt>
//#include <QtGui>
#include <QPainter>
#include <QPainterPath>
#include <QPixmap>
//#include <QColor>
//#include <QPointF>

AllocatedArray<RasterPoint> Canvas::vertex_buffer;

//------------------------------------------------------------------------------
Canvas::Canvas()
  : QWidget(0),
    offset(0, 0),
    size(0, 0),
    background_mode(OPAQUE)
  {
  }

//------------------------------------------------------------------------------
Canvas::Canvas(PixelSize size)
  : QWidget(0),
    offset(0, 0),
    size(size),
    background_mode(OPAQUE)
  {
  this->Create(size);
  }

//------------------------------------------------------------------------------
void
Canvas::Create(PixelSize size)
  {
  this->size = size;
  // \todo Set up canvas size.
//  QPixmap t(this->size.cx, this->size.cy);
//  this->pixmap = t;
  }

//------------------------------------------------------------------------------
bool
Canvas::IsDefined() const
  {
  return true;
  }

//------------------------------------------------------------------------------
PixelSize
Canvas::GetSize() const
  {
  return this->size;
  }

//------------------------------------------------------------------------------
unsigned
Canvas::GetWidth() const
  {
  return this->size.cx;
  }

//------------------------------------------------------------------------------
unsigned
Canvas::GetHeight() const
  {
  return this->size.cy;
  }

//------------------------------------------------------------------------------
void
Canvas::SelectNullPen()
  {
  this->pen = Pen(0, COLOR_BLACK);
  }

//------------------------------------------------------------------------------
void
Canvas::SelectWhitePen()
  {
  this->pen = Pen(1, COLOR_WHITE);
  }

//------------------------------------------------------------------------------
void
Canvas::SelectBlackPen()
  {
  this->pen = Pen(1, COLOR_BLACK);
  }

//------------------------------------------------------------------------------
void
Canvas::SelectHollowBrush()
  {
  this->brush.Destroy();
  }

//------------------------------------------------------------------------------
void
Canvas::SelectWhiteBrush()
  {
  this->brush = Brush(COLOR_WHITE);
  }

//------------------------------------------------------------------------------
void
Canvas::SelectBlackBrush()
  {
  this->brush = Brush(COLOR_BLACK);
  }

//------------------------------------------------------------------------------
void
Canvas::Select(const Pen &pen)
  {
  this->pen = pen;
  }

//------------------------------------------------------------------------------
void
Canvas::Select(const Brush &brush)
  {
  this->brush = brush;
  }

//------------------------------------------------------------------------------
void
Canvas::Select(const Font &font)
  {
  this->font = font;
  }

//------------------------------------------------------------------------------
void
Canvas::SetTextColor(const Color color)
  {
  this->text_color = color;
  }

//------------------------------------------------------------------------------
Color
Canvas::GetTextColor() const
  {
  return this->text_color;
  }

//------------------------------------------------------------------------------
void
Canvas::SetBackgroundColor(const Color color)
  {
  this->background_color = color;
  }

//------------------------------------------------------------------------------
Color
Canvas::GetBackgroundColor() const
  {
  return this->background_color;
  }

//------------------------------------------------------------------------------
void
Canvas::SetBackgroundOpaque()
  {
  this->background_mode = OPAQUE;
  }

//------------------------------------------------------------------------------
void
Canvas::SetBackgroundTransparent()
  {
  this->background_mode = TRANSPARENT;
  }

//------------------------------------------------------------------------------
void
Canvas::Rectangle(int left, int top, int right, int bottom)
  {
  this->DrawFilledRectangle(left, top, right, bottom, this->brush);

  if (this->IsPenOverBrush())
    this->DrawOutlineRectangle(left, top, right, bottom);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawFilledRectangle(int left, int top, int right, int bottom,
                            const Color color)
  {
  QPainterPath path;
  path.setFillRule(Qt::WindingFill);
  path.addRect(left, top, right - left, bottom - top);
  Brush a_brush(color);
  this->pushObject(path, this->pen(), a_brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawFilledRectangle(const PixelRect &rc, const Color color)
  {
  this->DrawFilledRectangle(rc.left, rc.top, rc.right, rc.bottom, color);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawFilledRectangle(int left,  int top,
                            int right, int bottom,
                           const Brush &brush)
  {
  if (!brush.IsHollow())
    this->DrawFilledRectangle(left, top, right, bottom, brush.GetColor());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawOutlineRectangle(int left, int top, int right, int bottom)
  {
  this->DrawOutlineRectangle(left, top, right, bottom, this->pen.GetColor());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawOutlineRectangle(int left,  int top,
                             int right, int bottom,
                             Color color)
  {
  QPainterPath p;
  p.addRect(left, top, right - left, bottom - top);
  QPen a_pen = this->pen();
  QBrush a_brush; // Qt::NoBrush.
#ifndef NDEBUG
  std::cerr << __FILE__ << ", " << __LINE__ << ": "
            << a_brush.color().red()   << ", "
            << a_brush.color().green() << ", "
            << a_brush.color().blue()  << std::endl;
#endif
  a_pen.setColor(QColor(color.Red(), color.Green(), color.Blue()));
  this->pushObject(p, a_pen, a_brush);
  }

//------------------------------------------------------------------------------
void
Canvas::FadeToWhite(uint8_t alpha)
  {
  const Color color(0xff, 0xff, 0xff, alpha);
  this->Clear(color);
  }

//------------------------------------------------------------------------------
void
Canvas::FadeToWhite(PixelRect rc, uint8_t alpha)
  {
  const Color color(0xff, 0xff, 0xff, alpha);
  DrawFilledRectangle(rc.left, rc.right, rc.right, rc.bottom, color);
  }

//------------------------------------------------------------------------------
void
Canvas::Clear()
  {
  // Delete all of the paths.
  this->objects.clear();
  }

//------------------------------------------------------------------------------
void
Canvas::Clear(const Color color)
  {
  this->Clear();
  this->DrawFilledRectangle(0, 0, this->GetWidth(), this->GetHeight(), color);
  }

//------------------------------------------------------------------------------
void
Canvas::Clear(const Brush &brush)
  {
  this->DrawFilledRectangle(0, 0, this->GetWidth(), this->GetHeight(), brush);
  }

//------------------------------------------------------------------------------
void
Canvas::ClearWhite()
  {
  this->Clear(COLOR_WHITE);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawRoundRectangle(int left, int top, int right, int bottom,
                           unsigned ellipse_x,
                           unsigned ellipse_y)
  {
  unsigned radius = std::min(std::min(ellipse_x, ellipse_y),
                                      unsigned(std::min(bottom - top,
                                                        right - left))) / 2u;
  QPainterPath p;
  p.addRoundedRect(left, top, right - left, bottom - top, radius, radius);
  pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawRaisedEdge(PixelRect &rc)
  {
  Pen bright(1, Color(240, 240, 240));
  this->Select(bright);
  this->DrawTwoLinesExact(rc.left,
                          rc.bottom - 2,
                          rc.left,
                          rc.top,
                          rc.right - 2,
                          rc.top);

  Pen dark(1, Color(128, 128, 128));
  this->Select(dark);
  this->DrawTwoLinesExact(rc.left + 1,
                          rc.bottom - 1,
                          rc.right - 1,
                          rc.bottom - 1,
                          rc.right - 1,
                          rc.top + 1);

  ++rc.left;
  ++rc.top;
  --rc.right;
  --rc.bottom;
  }

//------------------------------------------------------------------------------
void
Canvas::DrawPolyline(const RasterPoint *points, unsigned num_points)
  {
  unsigned i;
  QPainterPath p;
  QPointF v[num_points];
  for (i = 0; i < num_points; i++)
    {
    v[i].setX(points[i].x);
    v[i].setY(points[i].y);
    }
  p.moveTo(v[0]);
  for (i = 1; i < num_points; i++)
    p.lineTo(v[i]);
  pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawPolygon(const RasterPoint *points, unsigned num_points)
  {
  if (this->brush.IsHollow() && !this->pen.IsDefined())
    return;

  QPainterPath p;
  QVector<QPointF> v;
  for (unsigned i = 0; i < num_points; i++)
    {
    QPointF n;
    n.setX(points[i].x);
    n.setY(points[i].y);
    v.append(n);
    }
  QPolygonF z(v);
  p.addPolygon(z);
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawTriangleFan(const RasterPoint *points, unsigned num_points)
  {
  /*
   * A Triangle Fan is an OpenGL construct consist of a number of contiguous
   * triangles which share a common apex. The first of points defines the
   * common apex point.
   */
  if (this->brush.IsHollow() && !this->pen.IsDefined())
    return;

  unsigned i;
  QPainterPath p;
  QPointF v[num_points];
  for (i = 0; i < num_points; i++)
    {
    v[i].setX(points[i].x);
    v[i].setY(points[i].y);
    }
  
  // Draw the radials.
  for (i = 1; i < num_points; i++)
    {
    p.moveTo(v[0]);
    p.lineTo(v[i]);
    }

  // Draw the triangle bases.
  for (unsigned i = 1; i < (num_points - 1); i++)
    {
    p.moveTo(v[i]);
    p.lineTo(v[i + 1]);
    }
  this->pushObject(p, this->pen(), this->brush());  
  }

//------------------------------------------------------------------------------
void
Canvas::DrawHLine(int x1, int x2, int y, Color color)
  {
  QPainterPath p;
  p.moveTo(x1, y);
  p.lineTo(x2, y);
  QPen a_pen = this->pen();
  a_pen.setColor(QColor(color.Red(), color.Green(), color.Blue()));
  this->pushObject(p, a_pen, this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawLine(int ax, int ay, int bx, int by)
  {
  QPainterPath p;
  p.moveTo(ax, ay);
  p.lineTo(bx, by);
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawLine(const RasterPoint a, const RasterPoint b)
  {
  this->DrawLine(a.x, a.y, b.x, b.y);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawExactLine(int ax, int ay, int bx, int by)
  {
  this->DrawLine(ax, ay, bx, by);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawExactLine(const RasterPoint a, const RasterPoint b)
  {
  this->DrawExactLine(a.x, a.y, b.x, b.y);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawLinePiece(const RasterPoint a, const RasterPoint b)
  {
  this->DrawLine(a, b);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawTwoLines(int ax, int ay, int bx, int by, int cx, int cy)
  {
  this->DrawLine(ax, ay, bx, by);
  this->DrawLine(bx, by, cx, cy);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawTwoLines(const RasterPoint a,
                     const RasterPoint b,
                     const RasterPoint c)
  {
  this->DrawTwoLines(a.x, a.y, b.x, b.y, c.x, c.y);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawTwoLinesExact(int ax, int ay, int bx, int by, int cx, int cy)
  {
  this->DrawTwoLines(ax, ay, bx, by, cx, cy);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawCircle(int x, int y, unsigned radius)
  {
  QPainterPath p;
  p.addEllipse(x, y, 2 * radius, 2 * radius);
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawSegment(int x,
                    int y,
                    unsigned radius,
                    Angle start,
                    Angle end,
                    bool horizon)
  {
  QPainterPath p;
  QRectF r(x - radius, y - radius, 2 * radius, 2 * radius);
  p.arcMoveTo(r, start.Degrees());
  p.arcTo(r, start.Degrees(), end.Degrees() - start.Degrees());
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawAnnulus(int x, int y,
                    unsigned inner_r, unsigned outer_r,
                    Angle start, Angle end)
  {
  QPainterPath p;
  QRectF ri(x - inner_r, y - inner_r, 2 * inner_r, 2 * inner_r);
  QRectF ro(x - outer_r, y - outer_r, 2 * outer_r, 2 * outer_r);
  // Draw the inner radius of the annulus.
  p.arcMoveTo(ri, start.Degrees());
  p.arcTo(ri, start.Degrees(), end.Degrees() - start.Degrees());
  if (start != end)
    { // Only draw the end caps when needed.
    // The currentPosition() will be at the end of the inner circle. Draw
    // one side of the annulus.
    // \todo This doesn't work because Angle(360) != Angle(0)!
    double xx = (outer_r - inner_r) * cos(end.Radians()) +
                p.currentPosition().rx();
    double yy = (outer_r - inner_r) * -sin(end.Radians()) +
                p.currentPosition().ry();
    p.lineTo(xx, yy);
    }
  else
    p.arcMoveTo(ro, end.Degrees());  // Set up for the outer circle.
  // The currentPosition() will be at the 'end' of the outer circle. Draw the
  // outer to the start.
  p.arcTo(ro, end.Degrees(), start.Degrees() - end.Degrees());
  if (start != end)
    {// And close it off to finish up.
    p.closeSubpath();
    }
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawKeyhole(int x, int y,
                    unsigned inner_r, unsigned outer_r,
                    Angle start, Angle end)
  {
  // Make sure that the 'left' angle is first.
  QPainterPath path;
  path.setFillRule(Qt::WindingFill);
  Angle startN = this->normalize(start);
  Angle endN   = this->normalize(end);
  Angle a[4];
  a[2] = (startN > endN) ? startN : endN;
  a[3] = (startN > endN) ? endN : startN;
  a[0] = this->geo2Screen(a[3]);
  a[1] = this->geo2Screen(a[2]);
#ifndef NDEBUG
  std::cerr << __LINE__ << ": "
            << a[0].Degrees() << ", " << a[1].Degrees() << ", "
            << a[2].Degrees() << ", " << a[3].Degrees() << std::endl;
#endif
  // Draw the inner with a segment left out for the cone.
  path.arcMoveTo(this->boundingBox(x, y, inner_r), a[0].Degrees());
  path.arcTo(this->boundingBox(x, y, inner_r),
             a[0].Degrees(), 360.0 - fabs(a[1].Degrees() - a[0].Degrees()));
  // The currentPosition() will be at the end of the inner circle. Draw
  // one side of the cone.
  double xx = (outer_r - inner_r) * cos(a[1].Radians()) +
              path.currentPosition().rx();
  double yy = (outer_r - inner_r) * -sin(a[1].Radians()) +
              path.currentPosition().ry();
  path.lineTo(xx, yy);
  // Draw the outer arc of the cone.
  path.arcTo(this->boundingBox(x, y, outer_r),
             a[1].Degrees(), fabs(a[1].Degrees() - a[0].Degrees()));
  // This will draw the other side of the cone to finish the keyhole.
  path.closeSubpath();
  this->pushObject(path, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawFocusRectangle(PixelRect rc)
  {
  this->DrawOutlineRectangle(rc.left, rc.top, rc.right, rc.bottom,
                             COLOR_DARK_GRAY);
  }

//------------------------------------------------------------------------------
const PixelSize
Canvas::CalcTextSize(const TCHAR *text) const
  {
  QFontMetrics f(this->font());
  QSize s = f.size(Qt::TextSingleLine, QString(text));
  return {s.width(), s.height()};
  }

//------------------------------------------------------------------------------
unsigned
Canvas::CalcTextWidth(const TCHAR *text) const
  {
  return this->CalcTextSize(text).cx;
  }

//------------------------------------------------------------------------------
unsigned
Canvas::GetFontHeight() const
  {
  QFontMetrics f(this->font());
  return f.height();
  }

//------------------------------------------------------------------------------
void
Canvas::DrawText(int x, int y, const TCHAR *text)
  {
  QPainterPath p;
  p.addText(qreal(x), qreal(y), this->font(), QString(text));
  this->pushObject(p, this->pen(), this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawTransparentText(int x, int y, const TCHAR *text)
  {
  QPainterPath p;
  QPen a_pen(this->pen());
  QColor c = a_pen.color();
  c.setAlpha(128);
  a_pen.setColor(c);
  p.addText(qreal(x), qreal(y), this->font(), QString(text));
  this->pushObject(p, a_pen, this->brush());
  }

//------------------------------------------------------------------------------
void
Canvas::DrawClippedText(int x, int y, const PixelRect &rc, const TCHAR *text)
  {
    // XXX

  if (x < rc.right)
    this->DrawClippedText(x, y, rc.right - x, text);
  }

//------------------------------------------------------------------------------
void
Canvas::DrawClippedText(int x, int y, unsigned width, const TCHAR *text)
  {
  QPainterPath p;
  p.addText(qreal(x), qreal(y), this->font(), QString(text));
  QRegion r((QRect(x, y, width, this->font.GetHeight())));
  this->pushObject(p, this->pen(), this->brush(), r);
  }

//------------------------------------------------------------------------------
void
Canvas::TextAutoClipped(int x, int y, const TCHAR *t)
  {
  if (x < (int)GetWidth() && y < (int)GetHeight())
    this->DrawClippedText(x, y, GetWidth() - x, t);
  }

//------------------------------------------------------------------------------
void
Canvas::Stretch(int dest_x, int dest_y,
                unsigned dest_width, unsigned dest_height,
                const Bitmap &src,
                int src_x, int src_y,
                unsigned src_width, unsigned src_height)
  {
#if 0
  assert(IsDefined());
  assert(src.IsDefined());

  Stretch(dest_x, dest_y, dest_width, dest_height,
          src.GetNative(),
          src_x, src_y, src_width, src_height);
#endif
  }

//------------------------------------------------------------------------------
void
Canvas::Stretch(int dest_x, int dest_y,
                unsigned dest_width, unsigned dest_height,
                const Bitmap &_src)
  {
#if 0
  assert(IsDefined());
  assert(_src.IsDefined());

  ConstImageBuffer src = _src.GetNative();
  Stretch(dest_x, dest_y, dest_width, dest_height,
          src, 0, 0, src.width, src.height);
#endif
  }

//------------------------------------------------------------------------------
void
Canvas::Copy(int dest_x, int dest_y,
             unsigned dest_width, unsigned dest_height,
             const Bitmap &src, int src_x, int src_y)
  {
  this->Stretch(dest_x, dest_y, dest_width, dest_height,
                src, src_x, src_y, dest_width, dest_height);
  }

//------------------------------------------------------------------------------
void
Canvas::Copy(const Bitmap &src)
  {
  this->Copy(0, 0, src.GetWidth(), src.GetHeight(), src, 0, 0);
  }

//------------------------------------------------------------------------------
void
Canvas::StretchNot(const Bitmap &src)
  {
#if 0
  assert(_src.IsDefined());

  ConstImageBuffer src = _src.GetNative();
  const unsigned src_x = 0, src_y = 0;
  const unsigned dest_x = 0, dest_y = 0;
  const unsigned dest_width = GetWidth();
  const unsigned dest_height = GetHeight();

  SDLRasterCanvas canvas(buffer);
  BitNotPixelOperations<ActivePixelTraits> operations;

  canvas.ScaleRectangle(dest_x, dest_y, dest_width, dest_height,
                        src.At(src_x, src_y), src.pitch, src.width, src.height,
                        operations);
#endif
  }

//------------------------------------------------------------------------------
void
Canvas::Stretch(const Bitmap &src)
  {
  this->Stretch(0, 0, size.cx, size.cy, src);
  }

//------------------------------------------------------------------------------
void
Canvas::StretchMono(int dest_x, int dest_y,
                    unsigned dest_width, unsigned dest_height,
                    const Bitmap &src,
                    int src_x, int src_y,
                    unsigned src_width, unsigned src_height,
                    Color fg_color, Color bg_color)
  {
#if 0
  assert(IsDefined());
  assert(dest_width < 0x4000);
  assert(dest_height < 0x4000);

  if (dest_width >= 0x4000 || dest_height >= 0x4000)
    /* paranoid sanity check; shouldn't ever happen */
    return;

  SDLRasterCanvas canvas(buffer);

  OpaqueTextPixelOperations<ActivePixelTraits, GreyscalePixelTraits>
    opaque(canvas.Import(fg_color), canvas.Import(bg_color));

  canvas.ScaleRectangle<decltype(opaque), GreyscalePixelTraits>
    (dest_x, dest_y,
     dest_width, dest_height,
     src.At(src_x, src_y), src.pitch, src_width, src_height,
     opaque);
#endif
  }

//------------------------------------------------------------------------------
bool
Canvas::IsPenOverBrush() const
  {
  return pen.IsDefined() &&
         (brush.IsHollow() || brush.GetColor() != pen.GetColor());
  }

//------------------------------------------------------------------------------
void
Canvas::paintEvent(QPaintEvent *)
  {
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);
  for(QList<RenderObject *>::iterator it = this->objects.begin();
      it != this->objects.end();
      it++)
    {
#ifndef NDEBUG
    std::cerr << __FILE__ << ", " << __LINE__ << ": "
              << (*it)->brush().color().red()   << ", "
              << (*it)->brush().color().green() << ", "
              << (*it)->brush().color().blue()  << std::endl;
#endif
    p.setBrush((*it)->brush());
    p.setPen((*it)->pen());
    p.drawPath((*it)->painterPath());
    if (!(*it)->clipping().boundingRect().isNull())
      p.setClipRegion((*it)->clipping());
    }
  }

//------------------------------------------------------------------------------
inline Angle
Canvas::normalize(const Angle& a) const
  {
  double r = fmod(a.Radians(), 2.0 * M_PI);
  Angle ra = Angle::Radians(r);
#ifndef NDEBUG
  double ad = a.Degrees();
  double rd = ra.Degrees();
  std::cerr << __LINE__ << ": " << ad << ", " << rd << std::endl;
#endif
  return (ra);
  }

//------------------------------------------------------------------------------
inline QRectF
Canvas::boundingBox(qreal x, qreal y, qreal r) const
  {
  return QRectF(x - r, y - r, 2.0 * r, 2.0 * r);
  }

//------------------------------------------------------------------------------
inline Angle
Canvas::geo2Screen(const Angle& a) const
  {
  Angle r = -a + Angle::QuarterCircle();
  return r;
  }

//------------------------------------------------------------------------------
inline const QList<RenderObject *>::iterator
Canvas::pushObject(const QPainterPath path,
                   const QPen pen,
                   const QBrush brush,
                   const QRegion &clip)
  {
  RenderObject *o = new RenderObject(path);
  o->setPen(pen);
  o->brush(brush);
  o->clipping(clip);
  this->objects.push_back(o);
  return this->objects.end();
  }

