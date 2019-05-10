/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2018 Peter F Bradshaw
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

#ifndef _WAITSCREEN_HPP_
#define _WAITSCREEN_HPP_

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QString>
#include <QApplication>
#include <QPixmap>

/**
 * \class WaitScreen
 *
 * \brief Widget to signal progress of actions.
 *
 * This class represents a widget to indicate what is happening
 * to the program. It is used while loading maps for instance.
 *
 */
class WaitScreen : public QDialog
  {
  Q_OBJECT

public:

  WaitScreen(QWidget *parent=0);

  ~WaitScreen();

  void ScreenUsage(const bool arg)
    {
    this->screen_usage = arg;
    };

  bool ScreenUsage() const
    {
    return this->screen_usage;
    };


private:

  /**
   * flush all data out.
   */
  void flush();

public slots:

  /**
   * This slot is used to set the main text,
   * such as "Loading maps..."
   */
  void slot_SetText1(const QString& text);

  /**
   * This slot is used to set the secondary text,
   * such as the name of the airspace file that is being
   * loaded. It is also reset to an empty string if
   * SetText1 is called.
   */
  void slot_SetText2(const QString& text);

  /**
   * This slot is called to indicate progress. It is
   * used to rotate the glider-icon to indicate to the
   * user that something is in fact happening...
   */
  void slot_Progress(int stepsize=1);

private:

  QLabel* text1;
  QLabel* text2;

  QLabel* glider_label;

  QPixmap gliders;
  QPixmap glider;

  /**
   * Holds the current progress-value. Used to draw the
   * glider icon in the correct rotation.
   */
  int progress;

  int last_rot;
  bool screen_usage;
  };

#endif
