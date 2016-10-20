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

#include "Brush.hpp"
#include <QColor>
#include <Qt>

//------------------------------------------------------------------------------
Brush::Brush()
  {
  this->brush.setStyle(Qt::NoBrush);
  }

//------------------------------------------------------------------------------
Brush::Brush(const Color color)
  {
  this->Create(color);
  }

//------------------------------------------------------------------------------
Brush::Brush(const Brush& rhs)
  {
  this->brush = rhs.brush;
  }

//------------------------------------------------------------------------------
Brush&
Brush::operator=(const Brush& rhs)
  {
  this->brush = rhs.brush;
  return *this;
  }

//------------------------------------------------------------------------------
const QBrush&
Brush::operator()() const
  {
  return this->brush;
  }

//------------------------------------------------------------------------------
void
Brush::Create(const Color c)
  {
  int alpha = (c.IsTransparent() == true)? 128 : 255;
  this->brush.setColor(QColor(c.Red(), c.Green(), c.Blue(), alpha));
  this->brush.setStyle(Qt::SolidPattern);
  }

//------------------------------------------------------------------------------
void
Brush::Destroy()
  {
  this->brush.setStyle(Qt::NoBrush);
  this->defined = false;
  }

//------------------------------------------------------------------------------
bool
Brush::IsDefined() const
  {
  return this->brush.style() != Qt::NoBrush;
  }

//------------------------------------------------------------------------------
bool
Brush::IsHollow() const
  {
  return this->brush.style() == Qt::NoBrush;
  }

const Color
Brush::GetColor() const
  {
  return Color(this->brush.color().red(),
               this->brush.color().green(),
               this->brush.color().blue());
  }
