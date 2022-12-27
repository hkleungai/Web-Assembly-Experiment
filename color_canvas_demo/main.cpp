#include "../utils/c/extern.h"
#include "../utils/c/Array.h"
#include "Internal.h"

EXTERN {
  int*** get_c_pixels() {
    return Internal::get_c_pixels();
  }
  int get_canvas_width() {
    return Internal::WIDTH;
  }
  int get_canvas_height() {
    return Internal::HEIGHT;
  }
  int get_canvas_color_channel() {
    return Internal::COLOR_CHANNEL;
  }
  // Array<Array<Array<int>>>* get_pixels() {
  //   return Internal::get_pixels();
  // }
  // Array<int> *get_int_at(Array<Array<int>> *ints, int index) {
  //   return ints->at(index);
  // }
}

// #include <iostream>

// int main(void) {
//   if (1)
//     return 0;
//   // exit(0);

//   int a[100][200];

//   std::cout << sizeof(a) / sizeof(a[0]) << std::endl;

//   return 0;
// }
