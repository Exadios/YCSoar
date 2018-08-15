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

#ifndef _MAIN_HPP
#define _MAIN_HPP

#include <QObject>
#include <QString>
#include <boost/thread/thread.hpp>

class XCSoarThread;

/**
 * The main object. This object will launch the window system and the XCSoar
 * processes.
 */
class Main : public QObject
  {
  Q_OBJECT

public:
  /**
   * Ctor.
   * param argc Number of command line args.
   * param argv Vector of args.
   */
  Main(int argc, char *argv[]);

  /**
   * Run the program.
   */
  void run();

signals:
  void operate(const QString &);

public slots:
  /**
   * This is a signal received from the XCSoar thread to indicate that the
   * thread has terminated.
   */
  void xcsoarTerminated();

private:
  /**
   * The thread used to run the XCSoar routines.
   */
  boost::thread xcsoarThread;

  int argc;
  char **argv;

  };

#endif  //_MAIN_HPP
