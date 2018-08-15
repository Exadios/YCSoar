#include <QGuiApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QThread>
#include <iostream>

#include "Main.hpp"

int main(int argc, char *argv[])
  {
  QCoreApplication app(argc, argv);
  Main program(argc, argv);

  program.run();

  return app.exec();
  }
