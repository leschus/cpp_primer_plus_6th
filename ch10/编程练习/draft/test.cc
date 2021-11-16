#include <iostream>
using namespace std;

struct Name {
  char name[8];
};

int main() {
  // 根据已有知识, C++中数组之间是不可以直接进行赋值的, 赋值操作可以使用strcpy()完成
  // 但是, 当把数组包装在一个结构体中时, 两个这样的结构体变量之间却可以直接赋值
  // 如下:
  Name myname = {"Bob"};
  Name hisname;
  hisname = myname; // OK 暂无理论解释这一现象

  cout << "myname: " << myname.name << ", at " << (void *)(myname.name) << endl;
  cout << "hisname: " << hisname.name << ", at " << (void *)(hisname.name) << endl;
  /*
  输出结果:
  myname: Bob, at 0x61fdf0
  hisname: Bob, at 0x61fdc0
  */
}