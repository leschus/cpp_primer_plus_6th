#include <iostream>
#include <cstring>
#include "baddude.h"
using namespace std;

const int kSize = 5;

int main() {
  Person *guys[kSize];
  int count;
  for (count = 0; count < kSize; count ++) {
    char choice;
    cout << "Enter the person type:\n"
         << "g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit\n";
    cin >> choice;
    while (strchr("gpbq", choice) == NULL) {
      cout << "Please enter a g, p, b, or q: ";
      cin >> choice;
    }
    if (choice == 'q')
      break;
    string fname, lname;
    int cracks;
    cout << "Enter the firstname & lastname: ";
    cin >> fname >> lname;
    if (choice != 'p') {
      cout << "Enter the cracks number: ";
      cin >> cracks;
    }
    switch (choice) {
      case 'g':
        guys[count] = new Gunslinger(fname, lname, cracks);
        break;
      case 'p':
        guys[count] = new PokerPlayer(fname, lname);
        break;
      case 'b':
        guys[count] = new BadDude(fname, lname, cracks);
        break;
      default:
        cout << "You shouldn't be here.\n";
    }
    while (cin.get() != '\n') continue; // 消除缓冲区中可能存在的剩余字符
  }

  cout << "\nSome tests of member methods: \n";
  int i;
  for (i = 0; i < count; i++) {
    cout << endl;
    guys[i]->Show();  // 要呈现多态, Show()务必要声明为虚函数
  }

  for(i = 0; i < count; i++) {
    delete guys[i];   // 要正常析构, 基类析构函数务必声明为虚函数
  }
  cout << "Bye.\n";
}

/*
测试输出:

Enter the person type:
g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit
g
Enter the firstname & lastname: Bob Jones
Enter the cracks number: 12
Enter the person type:
g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit
p
Enter the firstname & lastname: Nancy Carter
Enter the person type:
g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit
b
Enter the firstname & lastname: Tom Hanks
Enter the cracks number: 35
Enter the person type:
g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit
b
Enter the firstname & lastname: Jackey Chan
Enter the cracks number: 36
Enter the person type:
g: Gunslinger  p: PokerPlayer  b: BadDude  q: quit
b
Enter the firstname & lastname: Jeff Stanson
Enter the cracks number: 99

Some tests of member methods:

Category: Gunslinger
Name: Bob Jones
Cracks: 12

Category: PokerPlayer
Name: Nancy Carter

Category: BadDude
Name: Tom Hanks
Cracks: 35

Category: BadDude
Name: Jackey Chan
Cracks: 36

Category: BadDude
Name: Jeff Stanson
Cracks: 99
Bye.

*/