//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T>
//   valarray<T>
//   atan2(const valarray<T>& x, const T& y);

#include <valarray>
#include <cassert>
#include <sstream>
#include <cstddef>

#include "test_macros.h"

bool is_about(double x, double y, int p)
{
    std::ostringstream o;
    o.precision(p);
    scientific(o);
    o << x;
    std::string a = o.str();
    o.str("");
    o << y;
    return a == o.str();
}

int main(int, char**)
{
    {
        typedef double T;
        T a1[] = {-.9, -.5, 0., .5, .75};
        T a3[] = {-8.7605805059819342e-01,
                  -5.8800260354756750e-01,
                   0.0000000000000000e+00,
                   5.8800260354756750e-01,
                   7.8539816339744828e-01};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<T> v3 = atan2(v1, .75);
        assert(v3.size() == v1.size());
        for (std::size_t i = 0; i < v3.size(); ++i)
            assert(is_about(v3[i], a3[i], 10));
    }

  return 0;
}
