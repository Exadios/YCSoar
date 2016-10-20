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

#include "SimpleCanvas.hpp"

#include <QApplication>
#include <QPainter>
#include <iostream>

//------------------------------------------------------------------------------
SimpleCanvas::SimpleCanvas()
  {
  }

//------------------------------------------------------------------------------
void
SimpleCanvas::Pen(const QPen& pen)
  {
  this->pen = pen;
  }

//------------------------------------------------------------------------------
void
SimpleCanvas::Brush(const QBrush& brush)
  {
  this->brush = brush;
  }

//------------------------------------------------------------------------------
void
SimpleCanvas::Path(const QPainterPath& path)
  {
  this->path = path;
  }

//------------------------------------------------------------------------------
void
SimpleCanvas::paintEvent(QPaintEvent *)
  {
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);
  p.setBrush(this->brush);
  p.setPen(this->pen);
//  p.fillPath(this->path, this->brush);
  p.drawPath(this->path);
  }

//------------------------------------------------------------------------------
int
main(int argc, char *argv[])
  {
  QApplication app(argc, argv);
  SimpleCanvas c;
  c.Pen(QPen(QColor(0, 0, 0, 255)));
  c.Brush(QBrush(QColor(128, 128, 0)));

  QPainterPath p;

  p.addEllipse(50, 50, 100, 100);
  c.Path(p);

  c.show();
  return app.exec();
  }

