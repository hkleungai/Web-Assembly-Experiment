#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

#include "../utils/Array.h"
#include "Internal.h"

extern "C"
{
  Array<Array<char>>* get_strings() {
    return &Internal::strings;
  };

  Array<char> *get_string_at(Array<Array<char>> *strings, int index)
  {
    return strings->at(index);
  }

  Array<Array<int>> *get_ints()
  {
    return &Internal::ints;
  };

  Array<int> *get_int_at(Array<Array<int>> *ints, int index)
  {
    return ints->at(index);
  }

  int get_array_attr_count() {
    return BaseArray::ATTR_COUNT;
  };
}
