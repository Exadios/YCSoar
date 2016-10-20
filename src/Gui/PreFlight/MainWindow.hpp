/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2015 Peter F Bradshaw
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

#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;
class QPlainTextEdit;
class QWizard;
class QSessionManager;
class QGroupBox;

/**
 * The PreFlight main window.
 */
class MainWindow : public QMainWindow
  {
  Q_OBJECT

public:
  /**
   * Ctor.
   */
  MainWindow();

  /**
   * Load a file and launch proceedure based on type.
   * @param fileName The name of the file of a certain type.
   */
  void loadFile(const QString &fileName);

protected:
  /**
   * This window is to close.
   * @param event The event.
   */
  void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
  void newFile();
  void open();
  bool save();
  bool saveAs();
  void about();
  void documentWasModified();
  void taskAction();
  void aircraftAction();

private:
  void createCommands();
  void createActions();
  void createMenus();
  void createToolBars();
  void createStatusBar();
  void readSettings();
  void writeSettings();
  bool maybeSave();
  bool saveFile(const QString &fileName);
  void setCurrentFile(const QString &fileName);
  QString strippedName(const QString &fullFileName);

  QGroupBox *selectorBox;
  QGroupBox *inputBox;
  QGroupBox *mainBox;
  QWizard *wizard;
  QString curFile;

  QMenu *fileMenu;
  QMenu *editMenu;
  QMenu *helpMenu;
  QToolBar *fileToolBar;
  QToolBar *editToolBar;
  QAction *newAct;
  QAction *openAct;
  QAction *saveAct;
  QAction *saveAsAct;
  QAction *exitAct;
  QAction *cutAct;
  QAction *copyAct;
  QAction *pasteAct;
  QAction *aboutAct;
  QAction *aboutQtAct;
  };

#endif  // __MAINWINDOW_H

