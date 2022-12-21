#ifndef INTERNAL_HEADER
#define INTERNAL_HEADER

#include "../utils/Array.h"

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
    , b[3] = { 3, 2, 5 }
    , c[3] = { 3, 7, 6 };

  Array<int> _ints[] = {
    make_array(int, a),
    make_array(int, b),
    make_array(int, c)
  };

  Array<Array<int>> ints = make_array(Array<int>, _ints);
}

#endif