#ifndef ARRAY_HEADER
#define ARRAY_HEADER

struct BaseArray {
  static const int ATTR_COUNT = 2;
};

template <class Type>
struct Array: public BaseArray
{
  Type *content;
  int length;
  

  Array(){};

  Array(Type *content, int length)
      : content(content),
        length(length){};

  Type *at(int index)
  {
    return &(this->content[index]);
  }
};

#define make_array(type, content) ( \
  Array<type>((type *)content, sizeof(content) / sizeof(type)) \
)

#endif