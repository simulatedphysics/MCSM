//
// Created by solidangle on 12/28/18.
//

/*
Copyright (c) 2013 Daniel Stahlke

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <fstream>
#include <vector>
#include <map>
#include <limits>
#include <cmath>
#include <cstdio>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>

// Warn about use of deprecated functions.
//#define GNUPLOT_DEPRECATE_WARN
#include "gnuplot-iostream.h"

#ifndef M_PI
#	define M_PI 3.14159265358979323846
#endif

// http://stackoverflow.com/a/1658429
//#ifdef _WIN32
//#include <windows.h>
//	inline void mysleep(unsigned millis) {
//		::Sleep(millis);
//	}
//#else
//#include <unistd.h>
//inline void mysleep(unsigned millis) {
//    ::usleep(millis * 1000);
//}
//#endif
//
//void pause_if_needed() {
//#ifdef _WIN32
//    // For Windows, prompt for a keystroke before the Gnuplot object goes out of scope so that
//	// the gnuplot window doesn't get closed.
//	std::cout << "Press enter to exit." << std::endl;
//	std::cin.get();
//#endif
//}
//
//// Tell MSVC to not warn about using fopen.
//// http://stackoverflow.com/a/4805353/1048959
//#if defined(_MSC_VER) && _MSC_VER >= 1400
//#pragma warning(disable:4996)
//#endif

#pragma once
void demo_basic() {
    Gnuplot gp;
    // For debugging or manual editing of commands:
    //Gnuplot gp(std::fopen("plot.gnu"));
    // or
    //Gnuplot gp("tee plot.gnu | gnuplot -persist");

    gp << "set xr [-0.5:3.5]\nset yr [-0.5:3.5]\n";
    gp << "unset tics\n";
    gp << "unset border\n";
    gp << "set size sq\n";
    gp << "set style line 1 lt 1 lc rgb \"black\" lw 2\n";
    gp << "set style fill solid 2.0 noborder\n";


//
//    gp << "set arrow 1 from 3,0 to 3,3 nohead ls 1\n";
//    gp << "set arrow 2 from 2,0 to 2,3 nohead ls 1 \n";
//    set arrow 3 from +1,0 to +1,+3 nohead ls 1 \
//    set arrow 4 from 0,0 to 0,+3 nohead ls 1 \
//    set arrow 5 from 0,+1 to +3,+1 nohead ls 1 \
//    set arrow 6 from 0,+2 to +3,+2 nohead ls 1 \
//    set arrow 7 from 0,+3 to +3,+3 nohead ls 1 \
//    set arrow 8 from 0,0 to +3,0 nohead ls 1";

    for(int i = 0; i < 4; i++)
        gp << std::string("set arrow ") + std::to_string(i+1) + " from " + "0," + std::to_string(i) + " to 3," + std::to_string(i) + " nohead ls 1\n";

    for(int i = 0; i < 4; i++)
        gp << std::string("set arrow ") + std::to_string(i+5) + " from " + std::to_string(i) + ",0 to " + std::to_string(i) + ",3 nohead ls 1\n";


    for (int i = 0; i<4; i++)
        for (int j = 0; j<4; j++)
            gp << "set object " + std::to_string(4*i+j+1) + " circle at " + std::to_string(j) + "," + std::to_string(i) + " size first 0.15 fc rgb \"navy\" front\n";
//    set object 2 circle at 0,1 size first 0.15 fc rgb "navy"
//    set object 3 circle at 0,2 size first 0.15 fc rgb "navy"
//    set object 4 circle at 0,3 size first 0.15 fc rgb "navy"
//    set object 5 circle at 1,0 size first 0.15 fc rgb "navy"
//    set object 6 circle at 1,1 size first 0.15 fc rgb "navy"
//    set object 7 circle at 1,2 size first 0.15 fc rgb "navy"
//    set object 8 circle at 1,3 size first 0.15 fc rgb "navy"
//    set object 9 circle at 2,0 size first 0.15 fc rgb "navy"
//    set object 10 circle at 2,1 size first 0.15 fc rgb "navy"
//    set object 11 circle at 2,2 size first 0.15 fc rgb "red" front
//    set object 12 circle at 2,3 size first 0.15 fc rgb "navy"


//    std::vector<std::pair<double, double> > xy_pts_A;
//    for(double x=-2; x<2; x+=0.01) {
//        double y = x*x*x;
//        xy_pts_A.emplace_back(std::make_pair(x, y));
//    }
//
//    std::vector<std::pair<double, double> > xy_pts_B;
//    for(double alpha=0; alpha<1; alpha+=1.0/24.0) {
//        double theta = alpha*2.0*3.14159;
//        xy_pts_B.emplace_back(std::make_pair(cos(theta), sin(theta)));
//    }

//    gp << "set xrange [-1.5:1.5]\nset yrange [-1.5:1.5]\n";
    gp << "plot '-' with points title 'cubic', '-' with points title 'circle'\n";
//    gp.send1d(xy_pts_A);
//    gp.send1d(xy_pts_B);

//    pause_if_needed();
}