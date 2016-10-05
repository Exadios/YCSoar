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

#ifndef __SIMPLECANVAS_HPP
#define __SIMPLECANVAS_HPP

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPainterPath>

class SimpleCanvas : public QWidget
  {
public:
  SimpleCanvas();

  SimpleCanvas(const SimpleCanvas& rhs) = delete;

  SimpleCanvas& operator=(const SimpleCanvas& rhs) = delete;

  void Pen(const QPen& pen);

  void Brush(const QBrush& brush);

  void Path(const QPainterPath& path);

protected:
  /**
   * Paint to the device (i.e. the #QWidget)
   * @param event Ignored.
   */
  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

  QPen pen;
  QBrush brush;
  QPainterPath path;
  };

#endif  // __SIMPLECANVAS_HPP`
