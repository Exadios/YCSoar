/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2018 Peter F Bradshaw
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

#include <unistd.h>
#include <QtGui>
#include <QGridLayout>

//#include "layout.h"
#include "WaitScreen.hpp"

//------------------------------------------------------------------------------
WaitScreen::WaitScreen(QWidget *parent) 
  : QDialog(parent, Qt::FramelessWindowHint),
    progress(0),
    last_rot(0),
    screen_usage(true)
  {
  this->setObjectName("WaitScreen");

//  int scale = Layout::getIntScaledDensity();
  int scale = 10;

  QGridLayout* topLayout  = new QGridLayout;
  topLayout->setMargin(5 * scale);
  topLayout->setSpacing(10);
  topLayout->setColumnMinimumWidth(0, 45);

  QGridLayout* backLayout = new QGridLayout(this);
  backLayout->setMargin(0);
  backLayout->addLayout(topLayout, 1, 1);
  backLayout->setRowMinimumHeight(0, 3 * scale);
  backLayout->setRowMinimumHeight(2, 3 * scale);
  backLayout->setColumnMinimumWidth(0, 3 * scale);
  backLayout->setColumnMinimumWidth(2, 3 * scale);

  QFrame* frm = new QFrame(this);
  frm->setFrameStyle(QFrame::Box | QFrame::Plain);
  frm->setLineWidth(3 * scale);
  backLayout->addWidget(frm, 0, 0, 3, 3);

  this->glider_label = new QLabel;
  topLayout->addWidget(glider_label, 0, 0, 3, 1);

  QLabel* txt = new QLabel(tr("Working, please wait!"), this);
  topLayout->addWidget(txt, 0, 1);

  this->text1 = new QLabel;
  topLayout->addWidget(this->text1, 1, 1);

  this->text2 = new QLabel;
  topLayout->addWidget(this->text2, 2, 1);

//  this->gliders = GeneralConfig::instance()->loadPixmap("gliders.png", false);
  this->gliders.load("gliders.png");
  this->glider = QPixmap(40, 40);
  this->glider.fill(palette().color(backgroundRole()));

  QPainter p(&this->glider);
  p.drawPixmap(0, 0, this->gliders);

  this->glider_label->setPixmap(this->glider);
  this->setVisible(true);
  }

//------------------------------------------------------------------------------
WaitScreen::~WaitScreen()
  {
  }

//------------------------------------------------------------------------------
/** This slot is used to set the main text, such as "Loading maps..." */
void WaitScreen::slot_SetText1(const QString& text)
  {
  this->text1->setText(text);
  this->text2->setText("");

  // qDebug("slot_Settext1(): text=%s\n", text.latin1());

  if (this->ScreenUsage())
    {
    this->slot_Progress(1);
    }
  else
    {
    this->flush();
    }
  }

//------------------------------------------------------------------------------
/**
 * This slot is used to set the secondary text, such as the name of the
 * airspace file that is being loaded. It is also reset to an empty string
 * if SetText1 is called.
 */
void WaitScreen::slot_SetText2(const QString& text)
  {
  QString shortText = text;

  if (text.length() > 32)
    {
    shortText="..." + text.right(32);

    int pos = shortText.lastIndexOf(QChar('/'));

    if (pos != -1)
      {
      // cut directory paths
      shortText = shortText.right(shortText.length() - pos - 1);
      }
    }

  this->text2->setText(shortText);

  if (this->ScreenUsage())
    {
    this->slot_Progress(1);
    }
  else
    {
    this->flush();
    }
  }

//------------------------------------------------------------------------------
/**
 * This slot is called to indicate progress. It is used to rotate the
 * glider-icon to indicate to the user that something is in fact happening...
 */
void WaitScreen::slot_Progress(int stepsize)
  {
  if (this->ScreenUsage() && isVisible())
    {
    this->progress += stepsize;

    int rot = this->progress % 24;  //we are rotating in steps of 15 degrees.

    if (this->last_rot != rot)
      {
      this->glider.fill(this->glider_label->palette().color(QPalette::Window));

      QPainter p(&this->glider);
      p.drawPixmap(0, 0, this->gliders, rot * 40, 0, 40, 40);
      this->glider_label->setPixmap(this->glider);

      this->last_rot = rot;
      this->setVisible(true);
      this->repaint();
      this->flush();
      }
    }
  }

void WaitScreen::flush()
  {
  QCoreApplication::flush();

#ifdef ANDROID
  QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents|QEventLoop::ExcludeSocketNotifiers);
#endif
  }
