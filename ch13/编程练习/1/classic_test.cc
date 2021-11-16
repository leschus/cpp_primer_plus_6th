#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd & disk);

int main() {
  Cd c1("Beatles", "Capitol", 14, 35.5);
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                       "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1;

  cout << "Using object derectly:\n";
  c1.Report();    // use Cd method
  c2.Report();    // use Classic method

  cout << "Using type Cd * pointer to objects:\n";
  pcd->Report();  // use Cd method for Cd object
  pcd = &c2;
  pcd->Report();  // use Classic method for Classic object

  cout << "Calling a function with a Cd reference argument:\n";
  Bravo(c1);
  Bravo(c2);

  cout << "Testing assignment:\n";
  Classic copy;
  copy = c2;
  copy.Report();

  cout << "Done!\n";
}

void Bravo(const Cd & disk) {
  disk.Report();
}

/*
测试结果:

Using object derectly:
          Performers: Beatles
               Label: Capitol
Number of selections: 14
      Total playtime: 35.50
          Performers: Alfred Brendel
               Label: Philips
Number of selections: 2
      Total playtime: 57.17
          Main works: Piano Sonata in B flat, Fantasia in C
Using type Cd * pointer to objects:
          Performers: Beatles
               Label: Capitol
Number of selections: 14
      Total playtime: 35.50
          Performers: Alfred Brendel
               Label: Philips
Number of selections: 2
      Total playtime: 57.17
          Main works: Piano Sonata in B flat, Fantasia in C
Calling a function with a Cd reference argument:
          Performers: Beatles
               Label: Capitol
Number of selections: 14
      Total playtime: 35.50
          Performers: Alfred Brendel
               Label: Philips
Number of selections: 2
      Total playtime: 57.17
          Main works: Piano Sonata in B flat, Fantasia in C
Testing assignment:
          Performers: Alfred Brendel
               Label: Philips
Number of selections: 2
      Total playtime: 57.17
          Main works: Piano Sonata in B flat, Fantasia in C
Done!

*/