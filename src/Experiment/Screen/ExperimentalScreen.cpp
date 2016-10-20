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

#include <QApplication>
#include "Screen/Canvas.hpp"
#include "Math/Angle.hpp"

#include <stdlib.h>
#include <iostream>

//------------------------------------------------------------------------------
int
main(int argc, char *argv[])
  {
  QApplication app(argc, argv);
  Canvas c;
  Pen(Pen::SOLID, 1, Color(0, 0, 0));
    {
    c.Select(Brush(Color(128, 128, 0, Color::TRANSPARENT)));
    c.DrawKeyhole(200, 100, 50, 100, Angle::Degrees(-20), Angle::Degrees(20));
    c.DrawKeyhole(400, 100, 50, 100, Angle::Degrees(70), Angle::Degrees(110));
    c.DrawKeyhole(200, 300, 50, 100, Angle::Degrees(160), Angle::Degrees(200));
    c.DrawKeyhole(400, 300, 50, 100, Angle::Degrees(-110), Angle::Degrees(-70));
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawKeyhole(200, 100, 50, 100, Angle::Degrees(35), Angle::Degrees(55));
    c.DrawKeyhole(400, 100, 50, 100, Angle::Degrees(125), Angle::Degrees(145));
    c.DrawKeyhole(200, 300, 50, 100, Angle::Degrees(215), Angle::Degrees(235));
    c.DrawKeyhole(400, 300, 50, 100, Angle::Degrees(305), Angle::Degrees(325));
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawFilledRectangle(0, 0, 100, 100, Color(128, 128, 128,
                                                Color::TRANSPARENT));
    c.DrawFilledRectangle(100, 100, 200, 200, Color(128, 0, 0,
                                                    Color::TRANSPARENT));
    c.DrawFilledRectangle(150, 150, 250, 250, Color(0, 128, 0,
                                                    Color::TRANSPARENT));
    c.DrawFilledRectangle(200, 200, 300, 300, Color(0, 0, 128,
                                                    Color::TRANSPARENT));
    c.DrawTransparentText(0, 0, "0");
    c.DrawTransparentText(0, 100, "100");
    c.DrawTransparentText(0, 200, "200");
    c.DrawTransparentText(0, 300, "300");
    c.DrawTransparentText(0, 400, "400");
    c.DrawTransparentText(0, 500, "500");
    c.DrawTransparentText(100, c.GetFontHeight(), "100");
    c.DrawTransparentText(200, c.GetFontHeight(), "200");
    c.DrawTransparentText(300, c.GetFontHeight(), "300");
    c.DrawTransparentText(400, c.GetFontHeight(), "400");
    c.DrawTransparentText(500, c.GetFontHeight(), "500");
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawOutlineRectangle(100, 100, 200, 200, Color(255, 0, 0));
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawRoundRectangle(100, 100, 200, 200, 10, 10);
    c.DrawRoundRectangle(200, 200, 300, 300, 100, 100);
    c.DrawRoundRectangle(300, 300, 400, 400, 50, 50);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    PixelRect rc;
    rc.left   = 100;
    rc.top    = 100;
    rc.right  = 200;
    rc.bottom = 200;
    c.DrawRaisedEdge(rc);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    RasterPoint rp[4];
    rp[0] = {100, 100};
    rp[1] = {200, 200};
    rp[2] = {200, 300};
    rp[3] = {300, 400};
    c.DrawPolyline(rp, 4);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    RasterPoint rp[6];
    rp[0] = {100, 100};
    rp[1] = {150,  50};
    rp[2] = {200, 100};
    rp[3] = {200, 200};
    rp[4] = {150, 200};
    rp[5] = {100, 100};
    c.DrawPolygon(rp, 6);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    RasterPoint rp[4];
    rp[0] = {100, 100};
    rp[1] = {200,  50};
    rp[2] = {200, 150};
    rp[3] = {150, 200};
    c.DrawTriangleFan(rp, 4);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawHLine(100, 200, 100, Color(255, 0, 0));
    c.DrawHLine(100, 200, 200, Color(0, 255, 0));
    c.DrawHLine(100, 200, 300, Color(0, 0, 255));
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawLine(100, 100, 200, 200);
    c.DrawCircle(250, 250, 50);
    c.DrawSegment(100, 250, 50, Angle::Degrees(10), Angle::Degrees(30), false);
    c.show();
    app.exec();
    }
    {
    c.Clear();
    c.DrawAnnulus(100, 100, 50, 100, Angle::Degrees(10), Angle::Degrees(60));
    c.DrawAnnulus(300, 100, 50, 100, Angle::Degrees(0),  Angle::Degrees(360));
    c.DrawAnnulus(100, 300, 50, 100, Angle::Degrees(0),  Angle::Degrees(0));
    c.show();
    app.exec();
    }
    {
    PixelSize rc = c.CalcTextSize("Hello");
    std::cout << "Size of \"Hello\": " << rc.cx << ", " << rc.cy << std::endl;
    c.DrawClippedText(100, 100, rc.cx / 2, "Hello");
    c.show();
    app.exec();
    }
    {
    std::cout << "Height of font: " << c.GetFontHeight() << std::endl;
    }
    {
    c.Clear();
    c.DrawText(0, 50, "50");
    c.Clear();
    c.show();
    return app.exec();
    }
  }
