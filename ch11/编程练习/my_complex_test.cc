#include <iostream>
#include "my_complex.h"

using namespace std;

int main() {
  Complex a(3.0, 4.0);
  Complex c;
  cout << "Enter a complex number (q to quit):\n";
  while (cin >> c) {
    cout << "c is " << c << endl;
    cout << "complex conjugate is " << ~c << endl;
    cout << "a is " << a << endl;
    cout << "a + c is " << a + c << endl;
    cout << "a - c is " << a - c << endl;
    cout << "a * c is " << a * c << endl;
    cout << "2 * c is " << 2 * c << endl;
    cout << "Enter a complex number (q to quit):\n";
  }
  cout << "Done!\n";
}

/*
测试结果:

Enter a complex number (q to quit):
real: 12
imaginary: 10
c is (12, 10i)
complex conjugate is (12, -10i)
a is (3, 4i)
a + c is (15, 14i)
a - c is (-9, -6i)
a * c is (-4, 78i)
2 * c is (24, 20i)
Enter a complex number (q to quit):
real: q
Done!

*/