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

/* (C) 2013-2023 Graeme Hattan & Bernd Porr & Fedor Chervyakov */

#ifndef MEDIAN_FILTER_H
#define MEDIAN_FILTER_H

#include <algorithm>
#include <iterator>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <limits>


/**
 * Causal median filter. The precision is double.
 * Computes median of last nTaps samples.
 * y(n) = med(x[n], x[n]-1, ... , x[n-nTaps])
 **/
class MedianFilter {
public:
  /** 
   * Inits the buffer to zero
   **/
  template <unsigned nTaps> MedianFilter() :
    buffer(new double[nTaps]()),
    temp(new double[nTaps]()),
    taps(nTaps) {
    // TODO: is this required? or new double[]() above should be enough?
    for(unsigned i=0;i<nTaps;i++) {
      buffer[i] = 0;
      temp[i] = 0;
    }
  }

  /** 
   * Inits all coefficients and the buffer to zero
   * This is useful for adaptive filters where we start with
   * zero valued coefficients.
   **/
  MedianFilter(unsigned number_of_taps);

  /**
   * Releases the coefficients and buffer.
   **/
  ~MedianFilter();

  /**
   * The actual filter function operation: it receives one sample
   * and returns one sample.
   * What is a median? a middle value in a sorted list
   * \param input The input sample.
   **/
  inline double filter(double input) {
    double *buf_val = buffer + offset;
    *buf_val = input;

    memcpy(temp, buffer, sizeof(double) * taps);
    std::sort(temp, temp+taps);

    double output_ = 0;

    if (taps % 2 == 0)
      output_ = 0.5 * (*(temp+taps/2) + *(temp+taps/2-1));
    else
      output_ = *(temp+(taps-1)/2);

    if (++offset >= taps)
      offset = 0;

    return output_;
  }


  /**
   * Resets the buffer
   **/
  void reset();

  /**
   * Returns the number of taps.
   **/
  unsigned getTaps() {return taps;};

private:
  double        *buffer;
  double        *temp;
  unsigned      taps;
  unsigned      offset = 0;
};

#endif
