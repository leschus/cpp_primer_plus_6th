#include <cassert>
#include <memory> // auto_ptr, unique_ptr, shared_pt
                  // 注: boost库中的scoped_ptr和shared_ptr提供类似功能
// #include <new>
#include <string>
#include <iostream>
#include <stdexcept>

using std::unique_ptr;
using std::shared_ptr;
// using std::auto_ptr; // no longer suppoted in c++11
using std::move;
using std::string;
using std::cout;
using std::endl;
using std::runtime_error;


class Demo {
 public:
  string str_;
  int n_;
  Demo(string str, int n) : str_(str), n_(n) {
    cout << "ctor called: " << str_ << ", " << n_ << endl;
  }
  bool operator==(const Demo &demo) {
    return str_ == demo.str_ && n_ == demo.n_;
  }
  ~Demo() {
    cout << "dtor called: " << str_ << ", " << n_ << endl;
  }
};


int main() {
  {
    Demo *p1 = new Demo("one", 1);
    delete p1;
  }
  {
    // std::unique_ptr<double> uptr(pi);
    unique_ptr<Demo> p2(new Demo("two", 2));
    unique_ptr<Demo> p3;
    // p3 = p2;   // not allowed
                    // unique_ptr的赋值运算符被定义为delete
                    // 即: unique_ptr& operator=(const unique_ptr&) = delete;
    p3 = move(p2);  // 可以使用move()来完成unique_ptr对象之间的赋值
                    // move()只是使得unique_ptr对象间的赋值能够通过编译, 但move()执行
                    // 完毕后, p2仍然是丢失了所有权, 因此再对p2执行解引用运算将会触发运
                    // 行时错误. 例如, 下面的assert语句将导致程序终止.
    // 无法使用C++标准异常机制捕获野指针解引用异常, 即, 下面的try-catch块不会像预期那样
    // 捕获到异常并进行处理.
    // try {
    //   assert(*p3 == *p2);
    // } catch (runtime_error e) {
    //   cout << "catch 1:\n";
    //   cout << e.what() << endl;
    // } catch (std::exception e) {
    //   cout << "catch 2:\n";
    //   cout << e.what() << endl;
    // } catch (...) {
    //   cout << "catch else.\n";
    // }
    // 实际上, p2在失去所有权之后, 其保存的原始指针值将被置为空, 因此, 可以将p2和nullptr
    // 进行比较以确认其是否仍具备对对象的唯一所有权
    if (p2 == nullptr) cout << "p2 is null now.\n";
    else cout << "p2 is not null now.\n";
  }
  {
    shared_ptr<Demo> p4(new Demo("four", 4));
    {
      shared_ptr<Demo> p5(p4);  // 引用计数加1
    }
    /* 使用unique_ptr来初始化shared_ptr时 */
    unique_ptr<Demo> p6(new Demo("six", 6));
    // shared_ptr<Demo> p7(p6);    // not allowed
                                // 这会导致p6丢失所有权
    // 而使用临时的unique_ptr可以初始化shared_ptr
    shared_ptr<Demo> p7(unique_ptr<Demo>(new Demo("seven", 7)));
  }
  cout << "Done.\n";
}

/*
测试输出:

ctor called: one, 1
dtor called: one, 1
ctor called: two, 2
p2 is null now.
dtor called: two, 2
ctor called: four, 4
ctor called: six, 6
ctor called: seven, 7
dtor called: seven, 7
dtor called: six, 6
dtor called: four, 4
Done.

*/