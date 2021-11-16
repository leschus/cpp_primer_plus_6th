#include <iostream>
using namespace std;
#include "vintage_port.h"

int main() {
  VintagePort vp1;
  vp1.Show();
  cout << vp1 << endl;

  cout << endl;

  VintagePort vp2("Qingdao", 20, "Chunsheng", 8);
  vp2.Show();
  cout << vp2 << endl;

  cout << endl;

  VintagePort vp3(vp2);
  vp2.Show();

  cout << endl;

  VintagePort vp4;
  vp4 = vp2;
  vp4.Show();
}