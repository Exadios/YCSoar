/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2016 Peter F Bradshaw
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

#include "LogFile.hpp"
#include "LocalPath.hpp"
#include "Asset.hpp"
#include "IO/TextWriter.hpp"
#include "Formatter/TimeFormatter.hpp"
#include "Time/BrokenDateTime.hpp"
#include "OS/FileUtil.hpp"

#include <stdio.h>
#include <stdarg.h>
#include <windef.h> // for MAX_PATH
#include <iostream>

//------------------------------------------------------------------------------
void
LogFormat(const char *fmt, ...)
  {
  char buf[MAX_PATH];
  va_list ap;

  va_start(ap, fmt);
  vsprintf(buf, fmt, ap);
  va_end(ap);

  std::cerr << buf << std::endl;
  }

#ifdef _UNICODE

//------------------------------------------------------------------------------
void
LogFormat(const TCHAR *Str, ...)
  {
  TCHAR buf[MAX_PATH];
  va_list ap;

  va_start(ap, Str);
  _vstprintf(buf, Str, ap);
  va_end(ap);

  std::cerr << buf << std::endl;
  }

#endif
