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

#include "ProcessFactory.hpp"
#include "OneSecTick.hpp"

#include <utility>
#include <iterator>
#include <string>

ProcessFactory *ProcessFactory::processFactory = nullptr;

//------------------------------------------------------------------------------
ProcessFactory::ProcessFactory()
  {
  this->processMap.clear();
  }

//------------------------------------------------------------------------------
ProcessFactory *
ProcessFactory::instance()
  {
  if (ProcessFactory::processFactory == nullptr)
    ProcessFactory::processFactory = new ProcessFactory;
  return ProcessFactory::processFactory;
  }

//------------------------------------------------------------------------------
boost::asio::io_service &
ProcessFactory::giveScheduler()
  {
  return this->scheduler;
  }

//------------------------------------------------------------------------------
std::shared_ptr<Process>
ProcessFactory::oneSecTick()
  {
  auto f = this->processMap.find(std::string("OneSecTick"));
  if (f == this->processMap.end())
    {
    auto p = new OneSecTick;
    std::shared_ptr<Process> q(p);
    auto r = this->processMap.insert({std::string("OneSecTick"), q});
    if (r.second == true)
      return r.first->second;
    else
      return nullptr;
    }
  return f->second;
  }
