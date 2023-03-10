/*
License: MIT License (http://www.opensource.org/licenses/mit-license.php)

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

/* (C) 2013 Graeme Hattan & Bernd Porr */
/* (C) 2018-2021 Bernd Porr */
/* (C) 2023 Fedor Chervyakov */

#include "MedianFilter1/MedianFilter.h"
#include <cstring>

MedianFilter::MedianFilter(unsigned number_of_taps) :
  buffer(new double[number_of_taps]()),
  temp(new double[number_of_taps]()),
  taps(number_of_taps)
{
}


MedianFilter::~MedianFilter()
{
  delete[] buffer;
  delete[] temp;
}


void MedianFilter::reset()
{
  memset(buffer, 0, sizeof(double) * taps);
  memset(temp, 0, sizeof(double) * taps);
}
