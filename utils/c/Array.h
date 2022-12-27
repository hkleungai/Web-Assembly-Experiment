#ifndef __USER_DEFINED__ARRAY_HEADER
#define __USER_DEFINED__ARRAY_HEADER

struct BaseArray {
  static const int ATTR_COUNT = 2;
};

template <class Type>
class Array: public BaseArray {
  Type *content;
  int length;

public:
  Array() {
    this->assign(nullptr, 0);
  };

  Array(Type *content, int length) {
    this->assign(content, length);
  }

  void assign(Type *content, int length) {
    this->content = content;
    this->length = length;
  }

  Type *at(int index) {
    return &(this->content[index]);
  }
};

#define make_array(type, content) ( \
  Array<type>((type *)content, sizeof(content) / sizeof(type)) \
)

#endif
