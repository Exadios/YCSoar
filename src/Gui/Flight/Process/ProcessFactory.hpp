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

#ifndef _PROCESSFACTORY_HPP_
#define _PROCESSFACTORY_HPP_

#include "Process.hpp"

#include <boost/asio.hpp>
#include <unordered_map>
#include <memory>
#include <string>


class Process;
class OneSecTick;

/**
 * A class to produce various XCSoar processes.
 *
 * \todo Write the xcsoarMain and other necessary processes
 */
class ProcessFactory
  {
public:

  typedef boost::asio::io_service Scheduler;
  typedef std::shared_ptr<Process> ProcessPtr;

  /**
   * Get the global instance of the factory. If the global instance does
   * not yet exist then create it. This is the only way of creating an
   * instance of this class.
   * @return The global instance.
   */
  static ProcessFactory *instance();

  /**
   * Give the scheduler.
   * @return The Boost Asio service.
   */
  Scheduler &giveScheduler();

  /**
   * Make a one second tick process. If the process does not yet exist
   * an attempt will be made to create it.
   * @return The base class of the process. This may be downcast using 
   *         dynamic_cast. This may be nullptr if the process does not
   *         yet exist and cannot be created for some reason.
   */
  ProcessPtr oneSecTick();

#if 0
  /**
   * Make the main XCSoar process. If the process does not yet exist
   * an attempt will be made to create it. (speculative at this time). 
   * @return The base class of the process. This may be downcast using 
   *         dynamic_cast. This may be nullptr if the process does not
   *         yet exist and cannot be created for some reason.
   */
  ProcessPtr xcsoarMain();
#endif

private:
  /**
   * Do not allow coping of this object by any means.
   */
  ProcessFactory();
  ProcessFactory(const ProcessFactory &);
  ProcessFactory operator=(const ProcessFactory &);

  typedef std::unordered_map<std::string, std::shared_ptr<Process> > ProcessMap;

  struct ProcessEntry
    {
    std::string key;
    Process *object;
    };

  boost::asio::io_service scheduler;

  static ProcessFactory *processFactory;

  ProcessMap processMap;
  };

#endif  // _PROCESSFACTORY_HPP_
