#include <inttypes.h>

class Color {
public:
  static const enum { R, G, B, A, RGBA_CHANNEL } ColorType;
  Color& operator=(uint32_t c);
private:
  int _[RGBA_CHANNEL];
};

#ifdef __USER_DEFINED__CANVAS_HEADER

Color& Color::operator=(uint32_t c) {
  this->_[R] = (c & 0xFF000000) / (1 << (4 * 2 * 3));
  this->_[G] = (c & 0x00FF0000) / (1 << (4 * 2 * 2));
  this->_[B] = (c & 0x0000FF00) / (1 << (4 * 2 * 1));
  this->_[A] = (c & 0x000000FF) / (1 << (4 * 2 * 0));
  return *this;
}
#endif // __USER_DEFINED__CANVAS_HEADER
