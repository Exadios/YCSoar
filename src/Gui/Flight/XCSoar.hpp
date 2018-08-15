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

#ifndef _XCSOAR_HPP_
#define _XCSOAR_HPP_

#include <boost/asio.hpp>
#include <memory>

/**
 * A Singleton class used to run the XCSoar processes.
 */
class XCSoar
  {
public:
  /**
   * Get an instance of the global XCSoar. If the global object does not
   * yet exist then it will be created. This is the only way to create an
   * object of this type.
   */
  static XCSoar *instance();

  /**
   * Run XCSoar routines (via Proactor)
   */
  void run();

  /**
   * Restart the scheduler after it has been stopped.
   */
  void restart();

  /**
   * Stop the scheduler.
   */
  void stop();

private:
  /**
   * Do not allow external construction or copying.
   */
  XCSoar();
  XCSoar(XCSoar &){};
  XCSoar &operator=(XCSoar const &){return *this;};

  static XCSoar *xcsoar;
  };

#endif  // _XCSOAR_HPP_
