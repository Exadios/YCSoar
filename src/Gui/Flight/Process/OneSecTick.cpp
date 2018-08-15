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

#include "OneSecTick.hpp"
#include "ProcessFactory.hpp"

#include <boost/bind.hpp>

//------------------------------------------------------------------------------
OneSecTick::OneSecTick()
  : timer(ProcessFactory::instance()->giveScheduler(),
          boost::posix_time::seconds(1))
  {
  }

//------------------------------------------------------------------------------
void
OneSecTick::initiator()
  {
  this->timer.async_wait(boost::bind(&OneSecTick::handler, this, _1));
  }

//------------------------------------------------------------------------------
void
OneSecTick::handler(const boost::system::error_code& error)
  {
  this->timer.expires_at(this->timer.expires_at() + boost::posix_time::seconds(1));
  this->timer.async_wait(boost::bind(&OneSecTick::handler, this, _1));
  }
