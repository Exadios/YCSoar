/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2015 Peter F Bradshaw
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

#include "LocalPathThunk.hpp"

#include <QString>

extern TCHAR *gcc_restrict data_path;
extern size_t data_path_length;

QString LocalPathThunk::cache;

//------------------------------------------------------------------------------
QString
LocalPathThunk::primaryDataPath() const
  {
  return ::GetPrimaryDataPath();
  }

//------------------------------------------------------------------------------
QString
LocalPathThunk::cacheDataPath() const
  {
  return this->cache;
  }

//------------------------------------------------------------------------------
LocalPathThunk::LocalPathThunk()
  {
  ::InitialiseDataPath();
  ::LocalPath(this->buffer, "cache");
  this->cache.clear();
  this->cache.prepend(this->buffer);
  }
