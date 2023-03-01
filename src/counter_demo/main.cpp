#include <cmath>
#include "../utils/c/extern.h"

EXTERN void fire(void);

EXTERN int get_count(float v) {
  fire();
  return (int)(cos(v) + sin(M_PI) + log10f(2000));
};
