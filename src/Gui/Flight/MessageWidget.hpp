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

/**
 * \class MessageWidget
 *
 * \author Axel Pauli
 *
 * \brief A dialog widget to display a question with yes and no buttons.
 *
 * This widget displays in a dialog a question with yes and no buttons.
 *
 * \date 2012
 *
 * \version $Id$
 *
*/
/**
 * \addtogroup Flight
 * @{
 */
#ifndef _MESSAGE_WIDGET_HPP_
#define _MESSAGE_WIDGET_HPP_

#include <QWidget>

class QShowEvent;
class QString;
class QTextEdit;

/**
 * \class MessageWidget
 *
 * \brief A dialog widget to display a question with yes and no buttons.
 *
 * This widget displays in a dialog a question with yes and no buttons.
 *
 *
*/

class MessageWidget : public QWidget
  {
  Q_OBJECT

private:

  Q_DISABLE_COPY ( MessageWidget )

public:

  /**
   * Ctor.
   * @param text The question.
   * @param parent This widget's parent.
   */
  MessageWidget(QString text, QWidget *parent = 0);

  /**
   * Dtor.
   */
  virtual ~MessageWidget();

protected:

  virtual void ShowEvent(QShowEvent *event);

signals:

  void yesClicked();
  void noClicked();

private:

  QTextEdit *text;
  };

#endif  // _MESSAGE_WIDGET_HPP_
/**
 * @}
 */
