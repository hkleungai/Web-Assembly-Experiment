#ifndef COUNTER_HEADER
#define COUNTER_HEADER

class Counter {
  long long count;

public:
  Counter(): count(0) {};

  void increment() {
    this->count++;
  }

  int get_count() {
    return this->count;
  }
};

#endif
