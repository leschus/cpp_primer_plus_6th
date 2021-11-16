#include <iostream>
using namespace std;
#include "dma.h"

const int MAX_NUM = 3;

int main() {
  DmaAbc *p_items[MAX_NUM];

  char tmp_label[80];
  int tmp_rating;
  char tmp_color[40];
  char tmp_style[80];
  char kind;
  char next;

  for (int i = 0; i < MAX_NUM; i++) {
    cout << "Enter 1 for BaseDma, 2 for LacksDma, 3 for HasDma: ";
    while (cin >> kind && (kind != '1' && kind != '2' && kind != '3')) {
      cout << "Enter 1, 2 or 3: ";
    }
    while (cin.get() != '\n') continue; // 处理上次输入时可能存在的多余字符
    cout << "Enter label: ";
    cin.get(tmp_label, 80);
    while (cin.get() != '\n') continue;
    cout << "Enter rating: ";
    cin >> tmp_rating;
    if (kind == '1') {
      p_items[i] = new BaseDma(tmp_label, tmp_rating);
    } else if (kind == '2') {
      while (cin.get() != '\n') continue;
      cout << "Enter color: ";
      cin.get(tmp_color, 40);
      p_items[i] = new LacksDma(tmp_color, tmp_label, tmp_rating);
    } else {
      while (cin.get() != '\n') continue;
      cout << "Enter style: ";
      cin.get(tmp_style, 80);
      p_items[i] = new HasDma(tmp_style, tmp_label, tmp_rating);
    }
    while (cin.get() != '\n') continue;
  }
  cout << "\n### Testing View():\n";
  for(int i = 0; i < MAX_NUM; i++) {
    // p_items[i]->View();    // 可以正确进行动态联编
    (*(p_items[i])).View();   // 仍可以正确进行动态联编
    cout << endl;
  }
  cout << "### Testing operator<<:\n";
  for(int i = 0; i < MAX_NUM; i++) {
    cout << *p_items[i] << endl;
    // 从输出结果来看, 这样做无法正确进行动态联编. why?
    // 确认了不是我代码写的有问题.
    // 因为使用书本上的程序清单13.14/13.15, 并修改程序
    // 清单13.16使其使用基类指针指向派生类对象进行测试,
    // 仍然出现一样的问题, 即无法触发动态联编.
    // >>> 记录为遗留问题.
  }

  for (int i = 0; i < MAX_NUM; i++) {
    delete p_items[i];  // free memory
  }

  cout << "### Testing copy constructior:\n";
  HasDma example("nonsence", "88888", 12);
  HasDma copy = example;
  // copy.View();
  cout << copy;
  cout << "\n### Testing assignment:\n";
  HasDma copy2;
  copy2 = example;
  // copy2.View();
  cout << copy2;

  cout << "\nDone!\n";
}