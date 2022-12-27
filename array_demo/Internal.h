#ifndef __USER_DEFINED__INTERNAL_HEADER
#define __USER_DEFINED__INTERNAL_HEADER

#include "../utils/c/Array.h"

namespace Internal {
  /* STRING */
  Array<char> _strings[] = {
    make_array(char, "Hello, HTML and Javascript"),
    make_array(char, "How are you?"),
    make_array(char, "I am from the C world!!")
  };

  Array<Array<char>> strings = make_array(Array<char>, _strings);

  /* INT */
  int a[3] = { 1, 2, 3 }
    , b[4] = { 3, 2, 5, 9 }
    , c[5] = { 3, 7, 6, 2, 7 };

  Array<int> _ints[] = {
    make_array(int, a),
    make_array(int, b),
    make_array(int, c)
  };

  Array<Array<int>> ints = make_array(Array<int>, _ints);
}

#endif