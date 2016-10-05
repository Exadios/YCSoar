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

#ifndef __RENDEROBJECT_HPP
#define __RENDEROBJECT_HPP

#include <QWidget>
#include <QPen>

class Brush;
class Pen;
class Color;

/**
 * A class to hold and render a graphical object.
 */
class RenderObject : public QWidget
  {
  Q_OBJECT

public:
  /**
   * @param path The path describing this object.
   * @param parent This object's parent widget.
   */
  explicit RenderObject(const QPainterPath &path, QWidget *parent = 0);

  /**
   * Specify the brush to use for this object.
   * @param b The XCSoar style brush.
   */
  void brush(const Brush b);

  /**
   * Specify the brush to use for this object.
   * @param b The Qt style brush.
   */
  void brush(const QBrush b);

  /**
   * Give this object's brush.
   * @return The QBrush.
   */
  const QBrush &brush() const;

  /**
   * Specify the pen color to use for this object.
   * @param c The XCSoar style color.
   */
  void penColor(const Color c);

  /**
   * Specify the pen to use.
   * @param The pen.
   */
  void setPen(const QPen pen);

  /**
   * Give this object's pen.
   * @return The QPen.
   */
  const QPen &pen() const;

  /**
   * Specify the rotation to apply to this object.
   * @param r The angle in degrees.
   */
  void rotation(int r);

  /**
   * Specify clipping.
   * @param r The clip region in Pixels. Zero width or height disables
   *          all clipping.
   */
  void clipping(const QRegion& r);

  /**
   * Give this object's clipping.
   * @return The clipping region.
   */
  QRegion clipping() const;

  /**
   * Give the path.
   * @return The QPainterPath.
   */
  const QPainterPath& painterPath() const;

protected:

private:
  QPainterPath path;
  QBrush fill;
  int penWidth;
  QPen bic;
  int rotationAngle;
  QRegion c;
  };

#endif  // __RENDEROBJECT_HPP

