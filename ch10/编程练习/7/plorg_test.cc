#include <iostream>
#include "plorg.h"

int main() {
  Plorg one;
  Plorg two("Nancy");
  Plorg three("aaaaabbbbbcccccdddd");
  one.report();
  two.report();
  two.update(32);
  two.report();
  three.report();
}