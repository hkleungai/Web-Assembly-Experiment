#ifndef INTERNAL_HEADER
#define INTERNAL_HEADER

// class Painter {
//   enum Color { R, G, B, A, COLOR_CHANNEL };

//   static const int WIDTH = 810, HEIGHT = 200;
//   int canvas[HEIGHT][WIDTH][COLOR_CHANNEL];

//   int x, y;
// };

namespace Internal {
  enum Color { R, G, B, A, COLOR_CHANNEL };

  const int WIDTH = 810, HEIGHT = 200;
  int canvas[HEIGHT][WIDTH][COLOR_CHANNEL];

  int*** get_c_pixels(float dt) {
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int mod = ((y + x * 8 / 7) / 29) % 3;
        // int mod = (((WIDTH - y + 1) + 3 * x) / 29) % 3;
        // int mod = ((y / 36) % 3 + (x / 36) % 3) % 3;
        canvas[y][x][R] = (mod == R ? 255 : 24);
        canvas[y][x][G] = (mod == G ? 255 : 24);
        canvas[y][x][B] = (mod == B ? 255 : 24);
        canvas[y][x][A] = 255;
      }
    }
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int foo = (((HEIGHT - y + 1) + x * 8 / 7) / 36);
        if (foo % 2)
          continue;
        canvas[y][x][R] = 147;
        canvas[y][x][G] = 112;
        canvas[y][x][B] = 219;
        canvas[y][x][A] = 255;
      }
    }
    for (int y = 0; y < HEIGHT; y++) {
      for (int x = 0; x < WIDTH; x++) {
        int foo = y + x * 8 / 7;
        if (((foo / 29) % 6) % 2)
          continue;
        int mod = (foo / 29 + 2) % 3;
        canvas[y][x][R] = (mod == R ? 255 : 24);
        canvas[y][x][G] = (mod == G ? 255 : 24);
        canvas[y][x][B] = (mod == B ? 255 : 24);
        canvas[y][x][A] = 255;
      }
    }
    return (int***)canvas;
  }
}

#endif
