#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <iostream>

#include "MainWindow.hpp"

int main(int argc, char *argv[])
  {
  QApplication app(argc, argv);

  QCoreApplication::setOrganizationName("YCSoar");
  QCoreApplication::setApplicationName("Pre Filght Tool");
  QCoreApplication::setApplicationVersion("V0.00");
  QCommandLineParser parser;
  parser.setApplicationDescription(QCoreApplication::applicationName());
  parser.addHelpOption();
  parser.addVersionOption();
  parser.addPositionalArgument("file", "The file to open.");
  parser.process(app);

  MainWindow mainWindow;
  if (!parser.positionalArguments().isEmpty())
    mainWindow.loadFile(parser.positionalArguments().first());
  mainWindow.show();
  return app.exec();
  }
