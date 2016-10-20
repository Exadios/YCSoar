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

#include "RenderObject.hpp"
#include "Color.hpp"
#include "Brush.hpp"

#include <QPainter>

//------------------------------------------------------------------------------
RenderObject::RenderObject(const QPainterPath &path, QWidget *parent)
  : QWidget(parent),
    path(path)
  {
  this->fill = QBrush(QColor(0, 0, 0), Qt::NoBrush);
  this->bic.setWidth(1);
  this->bic.setColor(QColor(0, 0, 0, 255));
  this->rotationAngle = 0;
  this->c = QRegion(QRect(0, 0, 0, 0));
  }

//------------------------------------------------------------------------------
void
RenderObject::brush(const Brush b)
  {
  this->fill = b();
  }

//------------------------------------------------------------------------------
void
RenderObject::brush(const QBrush b)
  {
  this->fill = b;
  }

//------------------------------------------------------------------------------
const QBrush&
RenderObject::brush() const
  {
  return this->fill;
  }

//------------------------------------------------------------------------------
void
RenderObject::penColor(const Color c)
  {
  this->bic.setColor(QColor(c.Red(), c.Green(), c.Blue(), 255));
  }

//------------------------------------------------------------------------------
void
RenderObject::setPen(const QPen pen)
  {
  this->bic = pen;
  }

//------------------------------------------------------------------------------
const QPen &
RenderObject::pen() const
  {
  return this->bic;
  }

//------------------------------------------------------------------------------
void
RenderObject::rotation(int r)
  {
  this->rotationAngle = r;
  }

//------------------------------------------------------------------------------
void
RenderObject::clipping(const QRegion &r)
  {
  this->c = r;
  }

//------------------------------------------------------------------------------
QRegion
RenderObject::clipping() const
  {
  return this->c;
  }

//------------------------------------------------------------------------------
const QPainterPath&
RenderObject::painterPath() const
  {
  return this->path;
  }

