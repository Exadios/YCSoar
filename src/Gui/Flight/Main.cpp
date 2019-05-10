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

#include "Main.hpp"
#include "XCSoarThread.hpp"
#include "MainWindow.hpp"

#include <QThread>
#include <QCoreApplication>
#include <QApplication>
#include <QScopedPointer>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include <iostream>
#include <unistd.h>

//------------------------------------------------------------------------------
Main::Main(int argc, char *argv[])
  : argc(argc),
    argv(argv)
  {
  }

//------------------------------------------------------------------------------
void
Main::run()
  {
  XCSoarThread xcsoar;

  boost::thread xcsoarThread(xcsoar);
  
  QApplication app(this->argc, this->argv);
  QCoreApplication::setApplicationName("YCSoar Flight");
  QCoreApplication::setApplicationVersion("V0.00");
  QCoreApplication::setOrganizationName("YCSoar");
  QCoreApplication::setOrganizationDomain("https://github.com/Exadios/YCSoar");

  QCommandLineParser parser;
  parser.setApplicationDescription(QCoreApplication::applicationName());
  parser.addHelpOption();
  parser.addVersionOption();
  parser.addPositionalArgument("file", "The file to open.");
  parser.process(app);

  MainWindow mainWindow;
//  mainWindow->show();
  app.exec();
//  delete mainWindow;
  this->xcsoarThread.join();
  }

//------------------------------------------------------------------------------
void
Main::xcsoarTerminated()
  {
  }

//------------------------------------------------------------------------------
/*
 * This is necessary for the boost lib when using -fnoexceptions.
 */
void
boost::throw_exception(std::exception const &e)
  {
  std::cerr << "Exception: " << e.what() << std::endl;
  }
