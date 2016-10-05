/*
 * G-Meter INU.
 * Copyright (C) 2013-2016 Peter F Bradshaw
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __CANVAS_HPP
#define __CANVAS_HPP

#include "Color.hpp"
#include "Point.hpp"
#include "PixelTraits.hpp"
#include "Buffer.hpp"
#include "ActivePixelTraits.hpp"
#include "Features.hpp"
#include "Brush.hpp"
#include "Font.hpp"
#include "Pen.hpp"
#include "RenderObject.hpp"
#include "Compiler.h"

#include <tchar.h>
#include <QPixmap>
#include <QImage>
#include <QWidget>

class Angle;
class Bitmap;
template<class T> class AllocatedArray;

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

/**
 * Base drawable canvas class for Qt.
 *
 * This is a drop in replacement of XCSoar's Canvas class.
 * 
 */
class Canvas : public QWidget
  {

  Q_OBJECT

  using ConstImageBuffer = ::ConstImageBuffer<ActivePixelTraits>;
public:
  /**
   * Ctor. Create a Canvas object with zero size and zero offset with an
   * opaque background.
   */
  Canvas();

  /**
   * Ctor. Create a Canvas object with a zero offset with an opaque background.
   * @param size The size of the canvas in pixels.
   */
  Canvas(PixelSize size);

  /**
   * Do not allow copying by any method.
   */
  Canvas(const Canvas &other) = delete;

  /**
   * Do not allow copying by any method.
   */
  Canvas &operator=(const Canvas &other) = delete;

  /**
   * Set size.
   * @param size The canvas size in pixels.
   */
  void Create(PixelSize size);


  /**
   * Is this object defined.
   * @return Always true.
   */
  bool IsDefined() const;

  /**
   * Give the size of the canvas.
   * @return The size on pixels.
   */
  PixelSize GetSize() const;

  /**
   * Give the width of the canvas.
   * @return The 'x' dimension in pixels.
   */
  unsigned GetWidth() const;

  /**
   * Give the height of the canvas.
   * @return The 'y' dimension in pixels.
   */
  unsigned GetHeight() const;

  gcc_pure
  PixelRect GetRect() const {
    return PixelRect(size);
  }

  /**
   * Select no pen (and make it black!).
   */
  void SelectNullPen();

  /**
   * Select pen 1 to white.
   */
  void SelectWhitePen();

  /**
   * Select pen 1 to black.
   */
  void SelectBlackPen();

  /**
   * Select a null brush.
   */
  void SelectHollowBrush();

  /**
   * Select a white brush.
   */
  void SelectWhiteBrush();

  /**
   * Select a black brush.
   */
  void SelectBlackBrush();

  /**
   * Select a pen.
   * @param pen The pen to use.
   */
  void Select(const Pen &pen);

  /**
   * Select a brush.
   * @param brush The brush to use.
   */
  void Select(const Brush &brush);

  /**
   * Select a font.
   * @param font The font to use.
   */
  void Select(const Font &font);

  /**
   * Select a color for text.
   * @param color The color to use for text.
   */
  void SetTextColor(const Color color);

  /**
   * Give the text color.
   * @return The current text color.
   */
  Color GetTextColor() const;

  /**
   * Set the background color.
   * @param color The new background color.
   */
  void SetBackgroundColor(const Color color);

  /**
   * Give the current background color.
   */
  Color GetBackgroundColor() const;

  /**
   * Make the background opaque.
   */
  void SetBackgroundOpaque();

  /**
   * Make the background tranparent.
   */
  void SetBackgroundTransparent();

  /**
   * Draw a filled rectangle with the current brush. Draw a an outline
   * around the filled rectangle with the current pen if necessary.
   * @param left The 'x' origin in pixels.
   * @param top The 'y' origin in pixels.
   * @param bottom The maximum 'x' extent in pixels.
   * @param right The maximum 'y' extent in pixels.
   */
  void Rectangle(int left, int top, int right, int bottom);

  /**
   * Draw a filled rectangle with a color.
   * @param left The 'x' origin in pixels.
   * @param top The 'y' origin in pixels.
   * @param bottom The maximum 'x' extent in pixels.
   * @param right The maximum 'y' extent in pixels.
   * @param color The color of the fill. Neither the state of the brush
   *              or pen color is modified by this function.
   */
  void DrawFilledRectangle(int left,  int top,
                           int right, int bottom,
                           const Color color);

  /**
   * Draw a filled rectangle with a brush.
   * @param left The 'x' origin in pixels.
   * @param top The 'y' origin in pixels.
   * @param bottom The maximum 'x' extent in pixels.
   * @param right The maximum 'y' extent in pixels.
   * @param brush The brush's color is the color of the fill.
   */
  void DrawFilledRectangle(int left,  int top,
                           int right, int bottom,
                           const Brush &brush);

  /**
   * Draw a filled rectangle with a brush.
   * @param rc The rectangle in pixels.
   * @param color The color of the fill. Neither the state of the brush
   *              or pen color is modified by this function.
   */
  void DrawFilledRectangle(const PixelRect &rc, const Color color);

  /**
   * @param rc
   * @param brush
   */
  void DrawFilledRectangle(const PixelRect &rc, const Brush &brush);

  /**
   * Draw the rectangle outline using the current pen.
   * @param left The 'x' origin.
   * @param top The 'y' origin.
   * @param bottom The maximum 'x' extant.
   * @param right The maximum 'y' extant.
   */
  void DrawOutlineRectangle(int left, int top, int right, int bottom);

  /**
   * Draw a rectangle outline with a color.
   * @param left The 'x' origin in pixels.
   * @param top The 'y' origin in pixels.
   * @param bottom The maximum 'x' extent in pixels.
   * @param right The maximum 'y' extent in pixels.
   * @param color The color of the fill. Neither the state of the brush
   *              or pen color is modified by this function.
   */
  void DrawOutlineRectangle(int left,  int top,
                            int right, int bottom,
                            Color color);

  /**
   * Fade to white.
   * @param rc The box defining the fade area.
   * @param alpha the alpha value, 0=no change, 0xff=fully white.
   */
  void FadeToWhite(PixelRect rc, uint8_t alpha);

  /**
   * Fade total canvas to white.
   * @param alpha the alpha value, 0=no change, 0xff=fully white.
   */
  void FadeToWhite(uint8_t alpha);

  /**
   * Clear the canvas to the current brush.
   */
  void Clear();

  /**
   * Clear the canvas to a color.
   * @param color The color which to clear to.
   */
  void Clear(const Color color);

  /**
   * Clear the canvas to the color of a brush.
   * @param brush The referebce brush.
   */
  void Clear(const Brush &brush);

  /**
   * Clear this canvas to white.
   */
  void ClearWhite();

  /**
   * A rectangle with rounded corners.
   * @param left The 'x' origin.
   * @param top The 'y' origin.
   * @param right The 'x' extent.
   * @param bottom The 'y' extent.
   * @param ellipse_width If this is smaller that ellipse_height then use this
   *                      as a corner radius hint. When the hint is large
   *                      compared to the smallest rectangle dimension then
   *                      use that dimension as the corner radius.
   * @param ellipse_width If this is smaller that ellipse_height then use this
   *                      as a corner radius hint. When the hint is large
   *                      compared to the smallest rectangle dimension then
   *                      use that dimension as the corner radius.
   */
  void DrawRoundRectangle(int left, int top, int right, int bottom,
                          unsigned ellipse_width, unsigned ellipse_height);

  /**
   * Draw a two pixel wide rectangular outline.
   * @param rc The rectangle dimensions. This is left two pixels smaller on
   *           return - i.e. the dimensions of the 'inner' rectangle.
   */
  void DrawRaisedEdge(PixelRect &rc);

  /**
   * Draw a polyline with the current pen.
   * @param points The array of vertices.
   * @param num_points How many vertices.
   */
  void DrawPolyline(const RasterPoint *points, unsigned num_points);

  /**
   * Draw a polygon with the current pen.
   * @param  points The array of vertices.
   * @param num_points How many vertices.
   */
  void DrawPolygon(const RasterPoint *points, unsigned num_points);

  /**
   * Draw a triangle fan.
   * A Triangle Fan is an OpenGL construct consist of a number of contiguous
   * triangles which share a common apex. The first of points defines the
   * common apex point.
   * @param points The vertices. The first point is the origin of the fan.
   * @param num_points How many vertices.
   */
  void DrawTriangleFan(const RasterPoint *points, unsigned num_points);

  /**
   * Draw a solid thin horizontal line.
   * @param x1 
   * @param x2
   * @param y
   * @param color The color of the line.
   */
  void DrawHLine(int x1, int x2, int y, Color color);

  /**
   * Draw a line from 'a' to 'b' using the current pen.
   * @param ax
   * @param ay
   * @param bx
   * @param by
   */
  void DrawLine(int ax, int ay, int bx, int by);

  /**
   * Draw a line from 'a' to 'b' using the current pen.
   * @param a
   * @param b
   */
  void DrawLine(const RasterPoint a, const RasterPoint b);

  /**
   * Similar to DrawLine(), but force exact pixel coordinates.  This
   * may be more expensive on some platforms, and works only for thin
   * lines.
   * @param ax
   * @param ay
   * @param bx
   * @param by
   */
  void DrawExactLine(int ax, int ay, int bx, int by);

  /**
   * Similar to DrawLine(), but force exact pixel coordinates.  This
   * may be more expensive on some platforms, and works only for thin
   * lines.
   * @param a
   * @param b
   */
  void DrawExactLine(const RasterPoint a, const RasterPoint b);

  /**
   * Draw a line from a to b, using triangle caps if pen-size > 2 to hide
   * gaps between consecutive lines.
   * @param a
   * @param b
   */
  void DrawLinePiece(const RasterPoint a, const RasterPoint b);

  /**
   * Draw a line from 'a' to 'b' to 'c' using the current pen.
   * @param ax
   * @param ay
   * @param bx
   * @param by
   * @param cx
   * @param cy
   */
  void DrawTwoLines(int ax, int ay, int bx, int by, int cx, int cy);

  /**
   * Draw a line from 'a' to 'b' to 'c' using the current pen.
   * @param a
   * @param b
   * @param c
   */
  void DrawTwoLines(const RasterPoint a,
                    const RasterPoint b,
                    const RasterPoint c);

  /**
   * @see DrawTwoLines(), DrawExactLine()
   * @param ax
   * @param ay
   * @param bx
   * @param by
   * @param cx
   * @param cy
   */
  void DrawTwoLinesExact(int ax, int ay, int bx, int by, int cx, int cy);

  /**
   * Draw a circle with the current pen.
   * @param x Center 'x'.
   * @param y Center 'y'.
   * @param radius The radu=ius in ??.
   */
  void DrawCircle(int x, int y, unsigned radius);

  /**
   * @param x Center 'x'.
   * @param y Center 'y'.
   * @param start Start angle in radians. North is zero.
   * @param end End angle in radians. North is zero.
   */
  void DrawSegment(int x, int y,
                   unsigned radius,
                   Angle start, Angle end,
                   bool horizon=false);

  /**
   * @param x
   * @param y
   * @param inner_r
   * @param outer_r
   * @param start
   * @param end
   * \todo This doesn't work correctly for the full circle because
   *       Angle(360) != Angle(0)!
   */
  void DrawAnnulus(int x, int y,
                   unsigned inner_r, unsigned outer_r,
                   Angle start, Angle end);

  /**
   * @param x
   * @param y
   * @param inner_r
   * @param outer_r
   * @param start
   * @param end
   */
  void DrawKeyhole(int x,
                   int y,
                   unsigned inner_r,
                   unsigned outer_r,
                   Angle start,
                   Angle end);

  /**
   * Draw a dark grey outline rectangle.
   * @param rc
   */
  void DrawFocusRectangle(PixelRect rc);

  /**
   * @param text
   * @param length
   * @return X, y size of text in pixels.
   */
  gcc_pure
  const PixelSize CalcTextSize(const TCHAR *text, size_t length) const;

  /**
   * @param text
   * @return X, y size of text in pixels.
   */
  gcc_pure
  const PixelSize CalcTextSize(const TCHAR *text) const;

  /**
   * @param text
   * @return x length of text in pixels.
   */
  gcc_pure
  unsigned CalcTextWidth(const TCHAR *text) const;

  /**
   * @return The height of the curerent font in pixels.
   */
  gcc_pure
  unsigned GetFontHeight() const;

  /**
   * @param x
   * @param y
   * @param text
   */
  void DrawText(int x, int y, const TCHAR *text);

  /**
   * @param x
   * @param y
   * @param text
   * @param length
   */
  void DrawText(int x, int y, const TCHAR *text, size_t length);

  /**
   * @param x
   * @param y
   * @param text
   */
  void DrawTransparentText(int x, int y, const TCHAR *text);

  /**
   * @param x
   * @param y
   * @param rc
   * @param text
   */
  void DrawOpaqueText(int x, int y, const PixelRect &rc,
                      const TCHAR *text);

  /**
   * @param x
   * @param y
   * @param rc
   * @param text
   */
  void DrawClippedText(int x, int y, const PixelRect &rc, const TCHAR *text);

  /**
   * @param x
   * @param y
   * @param width
   * @param text
   * \todo Doesn't clip text - fix.
   */
  void DrawClippedText(int x, int y, unsigned width, const TCHAR *text);

  /**
   * Render text, clip it within the bounds of this Canvas.
   * @param x
   * @param y
   * @param text
   */
  void TextAutoClipped(int x, int y, const TCHAR *t);

  /**
   * @param rc
   * @param text
   * @param format
   * \todo Is this used? If so implement.
   */
  void DrawFormattedText(PixelRect *rc, const TCHAR *text, unsigned format);

  /**
   * Draws a texture.  The caller is responsible for binding it and
   * enabling GL_TEXTURE_2D.
   * @param x
   * @param y
   * @param dest_width
   * @param dest_height
   * @param texture
   * @param src_x
   * @param src_y
   * @param src_width
   * @param src_height
   * \todo Is this used? If so figure out what is does and implement.
   */
  void Stretch(int dest_x, int dest_y,
               unsigned dest_width, unsigned dest_height,
               ConstImageBuffer src,
               int src_x, int src_y,
               unsigned src_width, unsigned src_height);

  /**
   * @param x
   * @param y
   * @param dest_width
   * @param dest_height
   * @param texture
   * \todo Is this used? If so figure out what is does and implement.
   */
  void Stretch(int dest_x, int dest_y,
               unsigned dest_width, unsigned dest_height,
               const Bitmap &_src);

  /**
   * @param dest_x
   * @param dest_y
   * @param dest_width
   * @param dest_height
   * @param src
   * @param src_x
   * @param src_y
   * \todo Implement.
   */
  void Copy(int dest_x, int dest_y,
            unsigned dest_width, unsigned dest_height,
            const Bitmap &src, int src_x, int src_y);

  /**
   * @param src
   * \todo Implement.
   */
  void Copy(const Bitmap &src);

  /**
   * @param src
   * \todo Is this used? If so figure out what is does and implement.
   */
  void StretchNot(const Bitmap &src);

  /**
   * @param dest_x
   * @param dest_y
   * @param dest_width
   * @param dest_height
   * @param src
   * @param src_x
   * @param src_y
   * \todo Is this used? If so figure out what is does and implement.
   */
  void Stretch(int dest_x, int dest_y,
               unsigned dest_width, unsigned dest_height,
               const Bitmap &src,
               int src_x, int src_y,
               unsigned src_width, unsigned src_height);

  /**
   * @param src
   * \todo Is this used? If so figure out what is does and implement.
   */
  void Stretch(const Bitmap &src);

  /**
   * Stretches a monochrome bitmap (1 bit per pixel), painting the
   * black pixels in the specified foreground color.  The white pixels
   * will be either transparent or drawn in the specified background
   * color, whichever operation is faster on the Canvas.
   *
   * @param dest_x
   * @param dest_y
   * @param dest_width
   * @param dest_height
   * @param src
   * @param src_x
   * @param src_y
   * @param fg_color draw this color instead of "black"
   * @param bg_color draw this color instead of "white"
   * \todo Is this used? If so figure out what is does and implement.
   */
  void StretchMono(int dest_x, int dest_y,
                   unsigned dest_width, unsigned dest_height,
                   const Bitmap &src,
                   int src_x, int src_y,
                   unsigned src_width, unsigned src_height,
                   Color fg_color, Color bg_color);

  void ScaleCopy(int dest_x, int dest_y,
                 const Bitmap &src,
                 int src_x, int src_y,
                 unsigned src_width, unsigned src_height);

protected:
  /**
   * Paint to the device (i.e. the #QWidget)
   * @param event Ignored.
   */
  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

  RasterPoint offset;
  PixelSize size;

  QImage pixmap;
  QPainterPath path;
  QList<RenderObject *> objects;

  Pen pen;
  Brush brush;
  Font font;
  Color text_color, background_color;
  enum
    {
    OPAQUE, TRANSPARENT
    }
  background_mode;

  /**
   * static buffer to store vertices of wide lines.
   */
  static AllocatedArray<RasterPoint> vertex_buffer;

  /**
   * @return true if the outline should be drawn after the area has
   *         been filled.  As an optimization, this function returns false if
   *         brush and pen share the same color.
   */
  bool IsPenOverBrush() const;

private:
  /**
   * Cast any angle to within [ 0, 2 * PI ] radians.
   * @param angle Unnormalize angle in radians
   * @return Normalized result.
   */
  inline Angle normalize(const Angle &angle) const;

  /**
   * Make a bounding box suitable for many Qt geometric shapes.
   * @param x Center x.
   * @param y Center y.
   * @param r Radius of the shape.
   * @return The Qt style bounding box.
   */
  inline QRectF boundingBox(qreal x, qreal y, qreal r) const;

  /**
   * Convert a Geo angle to a screen angle.
   * @param a The Geo angle.
   * @return The corresponding screen angle.
   */
  inline Angle geo2Screen(const Angle &a) const;

  /**
   * Pushes the painter path onto a stack for processing.
   * @param path The QPainterPath containing the drawable items.
   * @return A reference to the item pushed.
   */
  inline
  const QList<RenderObject *>::iterator pushObject(const QPainterPath path,
                                                   const QPen pen,
                                                   const QBrush brush,
                                                   const QRegion &clip = QRegion(QRect(0, 0, 0, 0)));

  friend class SubCanvas;
  friend class BufferCanvas;

  };

#endif  // __CANVAS_HPP
