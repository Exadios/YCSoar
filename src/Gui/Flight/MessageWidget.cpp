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

#include <QtWidgets>

#include "MessageWidget.hpp"

//------------------------------------------------------------------------------
MessageWidget::MessageWidget( QString text, QWidget *parent)
  : QWidget(parent)
  {
  qDebug() << "Here: " __FILE__ << ": " << __LINE__;
  QVBoxLayout *vbox = new QVBoxLayout(this);

  this->text = new QTextEdit(this);
  this->text->setReadOnly(true);

  if (text.contains("<html>", Qt::CaseInsensitive))
    {
    this->text->setHtml(text);
    }
  else
    {
    this->text->setPlainText(text);
    }

  vbox->addWidget(this->text);

  QPushButton *yes = new QPushButton(tr("Yes"));
  QPushButton *no  = new QPushButton(tr("No"));

  QHBoxLayout *buttonBox = new QHBoxLayout;
  buttonBox->addStretch(10);
  buttonBox->addWidget(yes);
  buttonBox->addSpacing(30);
  buttonBox->addWidget(no);
  buttonBox->addStretch(10);

  vbox->addLayout(buttonBox);

  connect(yes, SIGNAL(clicked()), this, SIGNAL(yesClicked()));
  connect(no, SIGNAL(clicked()), this, SIGNAL(noClicked()));

  if (parent)
    {
    this->resize(parent->size());
    }
  else
    {
    this->resize(QSize(800, 480));
    }

  this->setVisible(true);
  }

//------------------------------------------------------------------------------
MessageWidget::~MessageWidget()
  {
  }

//------------------------------------------------------------------------------
void MessageWidget::ShowEvent(QShowEvent *)
  {
  qDebug() << "Here: " __FILE__ << ": " << __LINE__;
  qDebug() << "MessageWidget::ShowEvent: font=" << font().toString();

  QSize ws = size();

  QTextDocument *doc = this->text->document();

  QSize ds = doc->size().toSize();

  while ( true )
    {
    ds = doc->size().toSize();

    qDebug() << "ds=" << ds << "ws=" << ws
             << "FPS=" << this->text->currentFont().pointSize()
             << "Diff=" << (ws - ds - QSize(20, 50 ));

    if ((ws - ds - QSize(20, 50)).isValid() == false)
      {
      this->text->zoomOut();
      continue;
      }
    break;
    }

  if (this->text->currentFont().pointSize() != -1 &&
      font().pointSize() != -1                    &&
      this->text->currentFont().pointSize() < font().pointSize())
    {
    int mwPs  = this->text->currentFont().pointSize();
    int guiPs = font().pointSize();

    // Make the global font smaller, if the document font was narrowed.
    QFont cf = font();
    cf.setPointSize(this->text->currentFont().pointSize());
    QApplication::setFont(cf);
    qDebug() << "MessageWidget: GUI font has narrowed from"
             << guiPs << "to" << mwPs;
    }
  }
