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

#ifndef __BRUSH_HPP
#define __BRUSH_HPP

#include "Screen/Color.hpp"
#include "Screen/Features.hpp"
//#include "Debug.hpp"
#include "Compiler.h"

#include <assert.h>
#include <QBrush>

/**
 * A Brush is used for drawing filled circles, rectangles and so on
 */
class Brush
  {
public:
  /**
   * Ctor. Creates a destroyed brush.
   */
  Brush();

  /**
   * Ctor. Creates a usable brush.
   * @param The color of the brush.
   */
  explicit Brush(const Color color);

  /**
   * Copy ctor.
   * @param rhs The reference object.
   */
  Brush(const Brush& rhs);

  /**
   * Assignment.
   * @param rhs The reference object.
   * @return This object.
   */
  Brush& operator=(const Brush& rhs);

  /**
   * Give the cannonical brush. This is mainly for use of the #Canvas class.
   * @return The real brush.
   */
  const QBrush& operator()() const;

  /**
   * Sets the Color of the Brush
   * @param c The new Color
   */
  void Create(const Color c);

  /**
   * Destroy the brush.
   */
  void Destroy();

  /**
   * Returns whether the Brush is defined (!= nullptr)
   * @return True if the Brush is defined, False otherwise
   */
  bool IsDefined() const;

  /**
   * @return If true then the brush will paint with no visible effect.
   */
  bool IsHollow() const;

  /**
   * The current color of the brush - irrespective of whether it is defined
   * or not.
   * @return Brush color.
   */
  const Color GetColor() const;

protected:
  /**
   * The cannonical brush.
   */
  QBrush brush;

private:
  bool defined;
  };

#endif  // __BRUSH_HPP

