/*
 * G-Meter INU.
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

#include <cxxtest/TestSuite.h>
#include "Brush.hpp"
#include "Pen.hpp"
#include "Font.hpp"
#include "Canvas.hpp"
#include "Math/Angle.hpp"

#include <stdlib.h>
#include <iostream>
#include <QApplication>

/**
 * Test.
 */

/**
 * Test the #Brush class.
 */
class BrushTest : public CxxTest::TestSuite
  {
public:
  /**
   * Basic ctor.
   */
  void testBasicCtor()
    {
    TS_TRACE("Brush basic ctor");
    Brush b;
    TS_ASSERT_EQUALS(b.IsDefined(), false);
    TS_ASSERT_EQUALS(b.IsHollow(), true);
    }
  };

/**
 * Test the #Font class.
 */
class FontTest : public CxxTest::TestSuite
  {
public:
  /**
   * Basic ctor.
   */
  void testBasicCtor()
    {
    int argc = 0;
    TS_TRACE("Font basic ctor");
    QApplication app(argc, (char **)nullptr, 0); // Necessary to run up a Font.
    Font f;
    TS_ASSERT_EQUALS(f.IsDefined(), false);
    }
  };

/**
 Test the #Pen class.
 */
class PenTest : public CxxTest::TestSuite
  {
public:
  /**
   * Basic ctor.
   */
  void testBasicCtor()
    {
    TS_TRACE("Pen basic ctor");
    Pen p;
    TS_ASSERT_EQUALS(p.GetWidth(), 1);
    TS_ASSERT_EQUALS(p.GetColor().Red(), 0);
    TS_ASSERT_EQUALS(p.GetColor().Green(), 0);
    TS_ASSERT_EQUALS(p.GetColor().Blue(), 0);
    TS_ASSERT_EQUALS(p.GetStyle(), Pen::SOLID);
    }

  /**
   * Basic set / get.
   */
  void testBasicSetGet()
    {
    TS_TRACE("Pen basic set get");
    Pen p;
    
    for (int i = 0; i < 10000; i++)
      {
      Pen::Style penmap[3] = {Pen::SOLID, Pen::DASH, Pen::BLANK};
      uint8_t refr, refg, refb;
      refr = rand();
      refg = rand();
      refb = rand();
      Color refc(refr, refg, refb);
      unsigned refw = lrand48();
      Pen::Style refs = penmap[rand() % sizeof(penmap)];
      Pen p(refs, refw, refc);
      TS_ASSERT_EQUALS(p.GetWidth(), refw);
      Color rc = p.GetColor();
      TS_ASSERT_EQUALS(rc.Red(), refr);
      TS_ASSERT_EQUALS(rc.Green(), refg);
      TS_ASSERT_EQUALS(rc.Blue(), refb);
      TS_ASSERT_EQUALS(p.GetStyle(), refs);
      }
    }
  };

/**
 * Test the #Canvas class.
 */
class CanvasTest : public CxxTest::TestSuite
  {
public:
  /**
   * Basic ctor.
   */
  void testBasicCtor()
    {
    int argc = 0;
    TS_TRACE("Canvas basic ctor");
    QApplication app(argc, (char **)nullptr, 0); // Necessary to run up a Canvas.
    Canvas c;
    TS_ASSERT_EQUALS(c.IsDefined(), true);
    TS_ASSERT_EQUALS(c.GetWidth(), 0);
    TS_ASSERT_EQUALS(c.GetHeight(), 0);
    }

  /**
   * Test a keyhole.
   */
  void notestKeyhole()
    {
    TS_TRACE("Canvas DrawKeyhole");
    int argc = 0;
    QApplication app(argc, (char **)nullptr, 0);
    Canvas c;
    Pen(Pen::SOLID, 1, Color(0, 0, 0));
    Brush(Color(128, 128, 0));
    c.DrawKeyhole(0, 0, 10, 20, Angle::Degrees(-10), Angle::Degrees(10));
    c.show();
    app.exec();
    }
  };
