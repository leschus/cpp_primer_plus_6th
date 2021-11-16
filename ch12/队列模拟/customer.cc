#include <cstdlib>
#include "customer.h"

Customer::Customer() {
  arrive_time_ = process_time_ = 0;
}

void Customer::set(long arrive_time) {
  arrive_time_ = arrive_time;
  process_time_ = rand() % 3 + 1;
}