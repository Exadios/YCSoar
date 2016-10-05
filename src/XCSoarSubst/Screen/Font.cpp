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

#include "Font.hpp"

#include "Screen/Debug.hpp"
#include "Thread/Mutex.hpp"
#include "Look/FontDescription.hpp"

#ifndef _UNICODE
#include "Util/UTF8.hpp"
#endif

#if defined(__clang__) && defined(__arm__)
/* work around warning: 'register' storage class specifier is
   deprecated */
#define register
#endif

#include <algorithm>
#include <QFontMetrics>

#include <assert.h>

//------------------------------------------------------------------------------
gcc_const
static inline bool
IsMono()
  {
  return false;
  }

//------------------------------------------------------------------------------
Font::Font()
  : initialized(false)
  {
  QFontMetrics m(this->font);
  this->height = m.height();
  this->ascent_height = m.ascent();
  this->capital_height = this->height;
  }

//------------------------------------------------------------------------------
Font::~Font()
  {
  }

//------------------------------------------------------------------------------
Font&
Font::operator=(const Font& rhs)
  {
  this->font           = rhs.font;
  this->line_spacing   = rhs.line_spacing;
  this->height         = rhs.height;
  this->ascent_height  = rhs.ascent_height;
  this->capital_height = rhs.capital_height;
  this->initialized    = rhs.initialized;
  return *this;
  }

//------------------------------------------------------------------------------
const QFont&
Font::operator()() const
  {
  return this->font;
  }

//------------------------------------------------------------------------------
bool
Font::IsDefined() const
  {
  return this->initialized;
  }

//------------------------------------------------------------------------------
bool
Font::Load(const FontDescription& d)
  {
  if (d.IsBold() == true)
    this->font.setWeight(QFont::Bold);
  else
    this->font.setWeight(QFont::Normal);
  if (d.IsItalic() == true)
    this->font.setStyle(QFont::StyleItalic);
  else
    this->font.setStyle(QFont::StyleNormal);
  if (d.IsMonospace() == true)
    this->font.setFamily("Courier");
  else
    this->font.setFamily("Sans");
  this->font.setPointSize(d.GetHeight());

  QFontMetrics m(this->font);
  this->height = m.height();
  this->ascent_height = m.ascent();
  this->capital_height = this->height;
  this->initialized = true;
  return true;
  }

//------------------------------------------------------------------------------
void
Font::Destroy()
  {
  this->initialized = false;
  }

//------------------------------------------------------------------------------
PixelSize
Font::TextSize(const TCHAR *text) const
  {
  assert(text != nullptr);
#ifndef _UNICODE
  assert(ValidateUTF8(text));
#endif
  QFontMetrics m(this->font);
  return { m.width(text), m.height() };
  }

//------------------------------------------------------------------------------
unsigned
Font::GetHeight() const
  {
  return this->height;
  }

//------------------------------------------------------------------------------
unsigned
Font::GetAscentHeight() const
  {
  return this->ascent_height;
  }

//------------------------------------------------------------------------------
unsigned
Font::GetCapitalHeight() const
  {
  return this->capital_height;
  }

//------------------------------------------------------------------------------
unsigned
Font::GetLineSpacing() const
  {
  QFontMetrics m(this->font);
  return m.lineSpacing();
  }
