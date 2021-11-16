#include <iostream>
#include "move.h"

int main() {
  Move m1(1.1, 2.2);
  Move m2(2.2, 1.1);

  m1.showmove();
  m2.showmove();

  Move new_m = m1.add(m2);
  new_m.showmove();
}