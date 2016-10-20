/*
 * YCSoar Glide Computer.
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

#ifndef __FONT_HPP
#define __FONT_HPP

#include "Point.hpp"
#include "Compiler.h"

#include <tchar.h>
#include <QFont>

class FontDescription;

/**
 * A font class to encapsulate QFont for the XCSoar library's benefit.
 * It is used by #Canvas to draw text.
 */
class Font
  {
public:
  /**
   * Ctor.
   */
  Font();

  /**
   * Dtor.
   */
  ~Font();

  /**
   * Do not allow copying of this object by this means
   */
  Font(const Font &other) = delete;

  /**
   * Allow copying of this object by this means
   * @param rhs The reference Font.
   * @return This object.
   */
  Font &operator=(const Font &rhs);

  /**
   * Give the reference QFont object. This is provided mainly for the Qt
   * #Canvas class.
   * @return The cannonical font.
   */
  const QFont& operator()() const;


  /**
   * @return Always true.
   */
  bool IsDefined() const;

  /**
   * Load a font.
   * @description A description of the font.
   * @return
   */
  bool Load(const FontDescription& description);

  /**
   * Undefine.
   */
  void Destroy();

  /**
   * Give the size of some text using the font.
   * @param text The text.
   * @return The x, y of the text in pixels.
   */
  gcc_pure
  PixelSize TextSize(const TCHAR *text) const;

  unsigned GetHeight() const;

  unsigned GetAscentHeight() const;

  unsigned GetCapitalHeight() const;

  unsigned GetLineSpacing() const;

protected:
  /**
   * The cannonical font;
   */
  QFont font;

  unsigned line_spacing;
  unsigned height, ascent_height, capital_height;

  void CalculateHeights();

private:
  /**
   * If initialized or not.
   */
  bool initialized;
  };

#endif  // __FONT_HPP
