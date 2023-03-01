#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <stdint.h>
#include "extern.h"

#define __USER_DEFINED__CANVAS_HEADER
#include "Canvas.h"

#include "Array.h"

#define CANVAS_HEIGHT 400
#define CANVAS_WIDTH 400

Color canvas[CANVAS_HEIGHT][CANVAS_WIDTH];

uint32_t init_color = 0x3232FFFF;

#ifdef WEB_ENV
  #define printf js__printf
  EXTERN int printf(Array<char> format);
#else
  #include <stdio.h>
#endif

EXTERN void render_c_pixels(double dt) {
  // printf(Array<char>((char*)s.c_str(), s.size()));
  // std::string s;
  // s.append("Text ");
  // s.append(std::to_string(dt));
  // printf(Array<char>((char*)s.c_str(), s.size()));

  std::stringstream ss;
  ss << std::fixed;
  ss << std::setprecision(10);
  ss << "Text " << dt << std::endl;
  std::string s = ss.str();
  printf(Array<char>((char *)s.c_str(), s.size()));

  for (int y = 0; y < CANVAS_HEIGHT; y++) {
    for (int x = 0; x < CANVAS_WIDTH; x++) {
      canvas[y][x] = 0x3232FFFF;
    }
  }
}

EXTERN int*** get_c_pixels() {
  return (int ***)canvas;
}

EXTERN int get_canvas_width() {
  return CANVAS_WIDTH;
}

EXTERN int get_canvas_height() {
  return CANVAS_HEIGHT;
}

EXTERN int get_canvas_color_channel() {
  return Color::RGBA_CHANNEL;
}
