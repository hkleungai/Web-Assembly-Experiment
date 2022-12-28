#include "../utils/c/extern.h"
#include "../utils/c/Array.h"
#include "Internal.h"

EXTERN Array<Array<char>>* get_strings() {
  return &Internal::strings;
};

EXTERN Array<char> *get_string_at(Array<Array<char>> *strings, int index) {
  return strings->at(index);
}

EXTERN Array<Array<int>> *get_ints() {
  return &Internal::ints;
};

EXTERN Array<int> *get_int_at(Array<Array<int>> *ints, int index) {
  return ints->at(index);
}

EXTERN int get_array_attr_count() {
  return BaseArray::ATTR_COUNT;
};
