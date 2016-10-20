/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2015 Peter F Bradshaw
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
#include <QWizardPage>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCommandLinkButton>
#include <QString>

#include "MainWindow.hpp"
#include "TaskWizard.hpp"

#include "ProfileThunk.hpp"
//#include "Profile/Current.hpp"
//#include "Profile/Settings.hpp"

#include <iostream>

//------------------------------------------------------------------------------
MainWindow::MainWindow()
  {
  this->wizard                = new TaskWizard;
  this->mainBox               = new QGroupBox;
  this->inputBox              = new QGroupBox;
  QVBoxLayout *mainLayout     = new QVBoxLayout;
  QHBoxLayout *inputLayout    = new QHBoxLayout;
  this->createCommands();
  mainLayout->addWidget(selectorBox);
  mainLayout->addWidget(inputBox);

  this->inputBox->setLayout(inputLayout);
  this->mainBox->setLayout(mainLayout);

  setCentralWidget(this->mainBox);

  this->createActions();
  this->createMenus();
  this->createToolBars();
  this->createStatusBar();

  this->readSettings();

  this->setCurrentFile("");
  this->setUnifiedTitleAndToolBarOnMac(true);
//  ProfileThunk *ProfileThunk = &ProfileThunk::Instance();
  }

//------------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent *event)
  {
  if (this->maybeSave())
    {
    this->writeSettings();
    event->accept();
    }
  else
    {
    event->ignore();
    }
  }

//------------------------------------------------------------------------------
void MainWindow::newFile()
  {
  if (this->maybeSave())
    {
//    this->textEdit->clear();
    this->setCurrentFile("");
    }
  }

//------------------------------------------------------------------------------
void MainWindow::open()
  {
  if (this->maybeSave())
    {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty())
      this->loadFile(fileName);
    }
  }

//------------------------------------------------------------------------------
bool MainWindow::save()
  {
  if (curFile.isEmpty())
    {
    return this->saveAs();
    }
  else
    {
    return this->saveFile(curFile);
    }
  }

//------------------------------------------------------------------------------
bool MainWindow::saveAs()
  {
  QFileDialog dialog(this);
  dialog.setWindowModality(Qt::WindowModal);
  dialog.setAcceptMode(QFileDialog::AcceptSave);
  QStringList files;
  if (dialog.exec())
    files = dialog.selectedFiles();
  else
    return false;

  return this->saveFile(files.at(0));
  }

//------------------------------------------------------------------------------
void MainWindow::about()
  {
   QMessageBox::about(this,
                      tr("About Application"),
                      tr("YCSoar PreFlight"));
  }

//------------------------------------------------------------------------------
void MainWindow::documentWasModified()
  {
//  this->setWindowModified(textEdit->document()->isModified());
  }

//------------------------------------------------------------------------------
void
MainWindow::createCommands()
  {
  this->selectorBox           = new QGroupBox;
  QHBoxLayout *selectorLayout = new QHBoxLayout;
  QCommandLinkButton *taskCommand  = new QCommandLinkButton;
  QCommandLinkButton *aircraftCommand = new QCommandLinkButton;
  taskCommand->setText(QString("Task"));
  aircraftCommand->setText(QString("Plane"));
  selectorLayout->addWidget(taskCommand);
  selectorLayout->addWidget(aircraftCommand);
  this->selectorBox->setLayout(selectorLayout);
  connect(taskCommand, SIGNAL(clicked()), this, SLOT(taskAction()));
  connect(aircraftCommand, SIGNAL(clicked()), this, SLOT(aircraftAction()));
  }

//------------------------------------------------------------------------------
void
MainWindow::taskAction()
  {
  TaskWizard wizard;
  wizard.exec();
  }

//------------------------------------------------------------------------------
void
MainWindow::aircraftAction()
  {
  }

//------------------------------------------------------------------------------
void MainWindow::createActions()
  {
  this->newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
  this->newAct->setShortcuts(QKeySequence::New);
  this->newAct->setStatusTip(tr("Create a new file"));
  connect(this->newAct, SIGNAL(triggered()), this, SLOT(newFile()));

  this->openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
  this->openAct->setShortcuts(QKeySequence::Open);
  this->openAct->setStatusTip(tr("Open an existing file"));
  connect(this->openAct, SIGNAL(triggered()), this, SLOT(open()));

  this->saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
  this->saveAct->setShortcuts(QKeySequence::Save);
  this->saveAct->setStatusTip(tr("Save the document to disk"));
  connect(this->saveAct, SIGNAL(triggered()), this, SLOT(save()));

  this->saveAsAct = new QAction(tr("Save &As..."), this);
  this->saveAsAct->setShortcuts(QKeySequence::SaveAs);
  this->saveAsAct->setStatusTip(tr("Save the document under a new name"));
  connect(this->saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

  this->exitAct = new QAction(tr("E&xit"), this);
  this->exitAct->setShortcuts(QKeySequence::Quit);
  this->exitAct->setStatusTip(tr("Exit the application"));
  connect(this->exitAct, SIGNAL(triggered()), this, SLOT(close()));

  this->cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
  this->cutAct->setShortcuts(QKeySequence::Cut);
  this->cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                          "clipboard"));
//  connect(this->cutAct, SIGNAL(triggered()), wizard, SLOT(cut()));

  this->copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
  this->copyAct->setShortcuts(QKeySequence::Copy);
  this->copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                           "clipboard"));
//  connect(this->copyAct, SIGNAL(triggered()), wizard, SLOT(copy()));

  this->pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
  this->pasteAct->setShortcuts(QKeySequence::Paste);
  this->pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                            "selection"));
//  connect(this->pasteAct, SIGNAL(triggered()), wizard, SLOT(paste()));

  this->aboutAct = new QAction(tr("&About"), this);
  this->aboutAct->setStatusTip(tr("Show the application's About box"));
  connect(this->aboutAct, SIGNAL(triggered()), this, SLOT(about()));

  this->aboutQtAct = new QAction(tr("About &Qt"), this);
  this->aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
  connect(this->aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  this->cutAct->setEnabled(false);
  this->copyAct->setEnabled(false);
  /*
  connect(this->textEdit,
          SIGNAL(this->copyAvailable(bool)),
          cutAct,
          SLOT(this->setEnabled(bool)));
  connect(textEdit,
          SIGNAL(this->copyAvailable(bool)),
          copyAct,
          SLOT(this->setEnabled(bool)));
  */
  }

//------------------------------------------------------------------------------
void MainWindow::createMenus()
  {
  this->fileMenu = menuBar()->addMenu(tr("&File"));
  this->fileMenu->addAction(newAct);
  this->fileMenu->addAction(openAct);
  this->fileMenu->addAction(saveAct);
  this->fileMenu->addAction(saveAsAct);
  this->fileMenu->addSeparator();
  this->fileMenu->addAction(exitAct);

  this->editMenu = menuBar()->addMenu(tr("&Edit"));
  this->editMenu->addAction(cutAct);
  this->editMenu->addAction(copyAct);
  this->editMenu->addAction(pasteAct);

  this->menuBar()->addSeparator();

  this->helpMenu = menuBar()->addMenu(tr("&Help"));
  this->helpMenu->addAction(aboutAct);
  this->helpMenu->addAction(aboutQtAct);
  }

void MainWindow::createToolBars()
  {
  this->fileToolBar = addToolBar(tr("File"));
  this->fileToolBar->addAction(newAct);
  this->fileToolBar->addAction(openAct);
  this->fileToolBar->addAction(saveAct);

  this->editToolBar = addToolBar(tr("Edit"));
  this->editToolBar->addAction(cutAct);
  this->editToolBar->addAction(copyAct);
  this->editToolBar->addAction(pasteAct);
  }

//------------------------------------------------------------------------------
void MainWindow::createStatusBar()
  {
  this->statusBar()->showMessage(tr("Ready"));
  }

//------------------------------------------------------------------------------
void MainWindow::readSettings()
  {
  QSettings settings("QtProject", "Application Example");
  QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
  QSize size = settings.value("size", QSize(400, 400)).toSize();
  resize(size);
  move(pos);
  }

//------------------------------------------------------------------------------
void MainWindow::writeSettings()
  {
  QSettings settings("QtProject", "Application Example");
  settings.setValue("pos", pos());
  settings.setValue("size", size());
  }

//------------------------------------------------------------------------------
bool MainWindow::maybeSave()
  {
  /*
  if (this->textEdit->document()->isModified())
    {
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this,
                               tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save |
                               QMessageBox::Discard |
                               QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
      return save();
    else if (ret == QMessageBox::Cancel)
      return false;
    }
  */
  return true;
  }

//------------------------------------------------------------------------------
void MainWindow::loadFile(const QString &fileName)
  {
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text))
    {
    QMessageBox::warning(this,
                         tr("Application"),
                         tr("Cannot read file %1:\n%2.").arg(fileName).arg(file.errorString()));
    return;
    }

  QTextStream in(&file);
#ifndef QT_NO_CURSOR
  QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
//  this->textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
  QApplication::restoreOverrideCursor();
#endif

  this->setCurrentFile(fileName);
  this->statusBar()->showMessage(tr("File loaded"), 2000);
  }

//------------------------------------------------------------------------------
bool MainWindow::saveFile(const QString &fileName)
  {
  QFile file(fileName);
  if (!file.open(QFile::WriteOnly | QFile::Text))
    {
    QMessageBox::warning(this,
                         tr("Application"),
                         tr("Cannot write file %1:\n%2.").arg(fileName).arg(file.errorString()));
    return false;
    }

  QTextStream out(&file);
#ifndef QT_NO_CURSOR
  QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
//  out << textEdit->toPlainText();
#ifndef QT_NO_CURSOR
  QApplication::restoreOverrideCursor();
#endif

  this->setCurrentFile(fileName);
  this->statusBar()->showMessage(tr("File saved"), 2000);
  return true;
  }

//------------------------------------------------------------------------------
void MainWindow::setCurrentFile(const QString &fileName)
  {
  this->curFile = fileName;
//  this->textEdit->document()->setModified(false);
  this->setWindowModified(false);

  QString shownName = curFile;
  if (curFile.isEmpty())
    shownName = "untitled.txt";
  this->setWindowFilePath(shownName);
  }

//------------------------------------------------------------------------------
QString MainWindow::strippedName(const QString &fullFileName)
  {
  return QFileInfo(fullFileName).fileName();
  }
