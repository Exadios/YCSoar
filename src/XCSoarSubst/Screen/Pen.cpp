/*
Copyright_License {

  G-Meter INU.
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

#include "Pen.hpp"
#include <Qt>

//------------------------------------------------------------------------------
Pen::Pen()
  {
  // Go with QPen defaults so do nothing other than initialization.
  }

//------------------------------------------------------------------------------
Pen::~Pen()
  {
  }

//------------------------------------------------------------------------------
Pen::Pen(const Pen& rhs)
  {
  this->pen = rhs.pen;
  }

//------------------------------------------------------------------------------
Pen&
Pen::operator=(const Pen& rhs)
  {
  this->pen = rhs.pen;
  return *this;
  }

//------------------------------------------------------------------------------
Pen::Pen(Style style, unsigned width, const Color color)
  {
  this->Create(style, width, color);
  }

//------------------------------------------------------------------------------
Pen::Pen(unsigned width, const Color color)
  {
  this->Create(width, color);
  }

//------------------------------------------------------------------------------
void
Pen::Create(Style style, unsigned width, const Color color)
  {
  this->pen.setStyle(this->xcsoar2QPenStyle(style));
  this->pen.setWidth(width);
  this->pen.setColor(QColor(color.Red(), color.Green(), color.Blue()));
  }

//------------------------------------------------------------------------------
void
Pen::Create(unsigned width, const Color color)
  {
  this->Create(SOLID, width, color);
  }

//------------------------------------------------------------------------------
void
Pen::Destroy()
  {
  this->pen.setWidth(0);
  }

//------------------------------------------------------------------------------
bool
Pen::IsDefined() const
  {
  return (this->pen.width() == 0) ? true : false;
  }

//------------------------------------------------------------------------------
unsigned
Pen::GetWidth() const
  {
  return this->pen.width();
  }

//------------------------------------------------------------------------------
const Color
Pen::GetColor() const
  {
  Color c(this->pen.color().red(),
          this->pen.color().green(),
          this->pen.color().blue());
  return c;
  }

//------------------------------------------------------------------------------
Pen::Style
Pen::GetStyle() const
  {
  return this->qpen2XCSoarStyle();
  }

//------------------------------------------------------------------------------
void
Pen::Bind()
  {
  // NOP.
  }

//------------------------------------------------------------------------------
void
Pen::Unbind()
  {
  // NOP.
  }

//------------------------------------------------------------------------------
const QPen&
Pen::operator()() const
  {
  return this->pen;
  }

//------------------------------------------------------------------------------
inline Pen::Style
Pen::qpen2XCSoarStyle() const
  {
  Style s;
  if (this->pen.style() == Qt::SolidLine)
    s = SOLID;
  else if (this->pen.style() == Qt::DashLine)
    s = DASH;
  else
    s = BLANK;  // Anything else, including Qt::NoPen, ....
  return s;
  }

//------------------------------------------------------------------------------
inline Qt::PenStyle
Pen::xcsoar2QPenStyle(Style style) const
  {
  Qt::PenStyle s;
  if (style == SOLID)
    s = Qt::SolidLine;
  else if (style == DASH)
    s = Qt::DashLine;
  else
    s = Qt::NoPen;  // Anything else, including BLANK, ...
  return s;
  }
