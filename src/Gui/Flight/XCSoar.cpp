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

#include "XCSoar.hpp"
#include "Process/ProcessFactory.hpp"

#include <unistd.h>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/error.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

XCSoar *XCSoar::xcsoar = nullptr;

//------------------------------------------------------------------------------
XCSoar::XCSoar()
  {
  ProcessFactory::instance();
  }

//------------------------------------------------------------------------------
XCSoar *
XCSoar::instance()
  {
  if (XCSoar::xcsoar == nullptr)
    XCSoar::xcsoar = new XCSoar;
  return XCSoar::xcsoar;
  }

//------------------------------------------------------------------------------
void
XCSoar::run()
  {
#if 0
  if (this->processTimer == false)
    {
    this->processTimer(new boost::asio::deadline_timer(*(this->scheduler),
                                                       boost::posix_time::seconds(1)));
    this->processTimer->async_wait(boost::bind(this->oneSecTick,
                                   boost::asio::placeholders::error,
                                   *(this->processTimer)));
    this->restart();
    
    std::cout << __FILE__ << ": " << __LINE__ << std::endl;
    }
#endif
  }

//------------------------------------------------------------------------------
void
XCSoar::restart()
  {
#if 0
  this->scheduler.reset();
  this->scheduler.run();
#endif
  }

//------------------------------------------------------------------------------
void
XCSoar::stop()
  {
#if 0
  this->scheduler.stop();
#endif
  }

//------------------------------------------------------------------------------
#if 0
void
XCSoar::oneSecTick(const boost::system::error_code &e,
                   boost::asio::deadline_timer *t)
  {
  std::cout << __FILE__ << ": " << __LINE__ << std::endl;
  t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
  t->async_wait(boost::bind(this->oneSecTick,
                            boost::asio::placeholders::error,
                            t));
  }
#endif
