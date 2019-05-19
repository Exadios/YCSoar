/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2019 Peter F Bradshaw
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

/**
 * \addtogroup Screen
 * @{
 */
#ifndef __PEN_HPP
#define __PEN_HPP

#include "Screen/Color.hpp"
#include <QPen>

/**
 * Definition of the graphics pen. This class encapsulaes Qt QPen for the
 * XCSoar library.
 */
class Pen
  {
public:

  /**
   * The XCSoar pen style specification.
   */
  enum Style : uint8_t
    {
    SOLID,
    DASH,
    BLANK
    };

  /**
   * Ctor.
   */
  Pen();

  /**
   * Dtor.
   */
  ~Pen();

  /**
   * Copy ctor.
   * @param rhs The reference Pen.
   */
   Pen(const Pen& rhs);

   /**
    * Copy operator.
    * @param rhs The reference Pen.
    * @return This Pen.
    */
   Pen& operator=(const Pen& rhs);

   /**
    * Ctor.
    * @param style One of Pen::Style.
    * @param width Pen width in pixels.
    * @param color The Color (R, G, B).
    */
   Pen(Style style, unsigned width, const Color color);

   /**
    * Ctor.
    * @param width Pen width in pixels.
    * @param color The Color (R, G, B).
    */
   Pen(unsigned width, const Color color);

   /**
    * Initialize the object. Needed for compatibility with XCSoar's Pen.
    * @param style One of Pen::Style.
    * @param width Pen width in pixels.
    * @param color The Color (R, G, B).
    */
   void Create(Style style, unsigned width, const Color color);

   /**
    * Initialize the object. Needed for compatibility with XCSoar's Pen.
    * @param width Pen width in pixels.
    * @param color The Color (R, G, B).
    */
   void Create(unsigned width, const Color color);

  /**
   * Set the pen to no pen.
   */
  void Destroy();

  /**
   * Is there a pen?
   * @return If there is a pen then true.
   */
  bool IsDefined() const;

  /**
   * The current pen width.
   * @return The width in pixels.
   */
  unsigned GetWidth() const;

  /**
   * The current pen color.
   * @return The current Color (R, B, G).
   */
  const Color GetColor() const;

  /**
   * The current style. This function is not in XCSoar's Pen class.
   * @return The Style.
   */
  Style GetStyle() const;

  /**
   * NOP. Required for interface compatibility.
   */
  void Bind();

  /**
   * NOP. Required for interface compatibility.
   */
  void Unbind();

  /**
   * Give the underlying QPen. This is usefull for those classes that use Qt.
   * This function is not in XCSoar's Pen class.
   * @return The underlying QPen object held by this object.
   */
  const QPen& operator()() const;

protected:
  /**
   * The XCSoar color object. This class will keep this object in sync with
   * the QPen object.
   */
  Color color;

  /**
   * The XCSoar width property. This class will keep this property in sync with
   * the QPen object.
   */
  uint8_t width;

  /**
   * The XCSoar style property. This class will keep this property in sync with
   * the QPen object.
   */
  Style style;

private:
  /**
   * The reference pen.
   */
  QPen pen;

  /**
   * Give the current XCSoar style from this object's QPen.
   * @return The cuurent style in a form suitable for the XCSoar library.
   */
  Style qpen2XCSoarStyle() const;

  /**
   * Give the Qt pen style from the XCSoar library style.
   * @param style The pen sytle in XCSoar's library format.
   * @return The pen style in Qt format.
   */
  Qt::PenStyle xcsoar2QPenStyle(Style style) const;
  };

#endif  // __PEN_HPP
/**
 * @}
 */
