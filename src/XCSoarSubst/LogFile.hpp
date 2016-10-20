/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2016 Peter F Bradshaw
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

#ifndef __LOGFILE_HPP
#define __LOGFILE_HPP

#include "Compiler.h"

#ifdef _UNICODE
#include <tchar.h>
#endif

/**
 * Write a formatted line to the log file.
 *
 * @param fmt the format string, which must not contain newline or
 * carriage return characters
 */
gcc_printf(1, 2)
void
LogFormat(const char *fmt, ...);

#ifdef _UNICODE
void
LogFormat(const TCHAR *fmt, ...);
#endif

#if !defined(NDEBUG) && !defined(GNAV)

#define LogDebug(...) LogFormat(__VA_ARGS__)

#else /* NDEBUG */

/* not using an empty inline function here because we don't want to
   evaluate the parameters */
#define LogDebug(...)

#endif /* NDEBUG */

#endif  // __LOGFILE_HPP
