// using queue

// queue基于deque实现, 但其操作受限, 不可随机访问队列元素, 不可遍历队列.
// 其支持的基本操作如下:
//    * 判空: empty()
//    * 获得元素个数: size()
//    * 入队: push(e)
//    * 出队: pop()
//    * 获得队头元素: front()
//    * 获得队尾元素: back()
//
// 除此之外, 代码补全机制会提示queue对象还可以调用emplace()方法和swap()方法.
//    * q.emplace(e): 入队. 将e作为参数调用拷贝构造函数创建新元素, 该元素直接作为队尾元素;
//                  而传统的push(e)方法则是先基于e利用拷贝构造函数创建一个临时变量, 再将
//                  该变量赋值给队尾的新元素. 由此可以看出emplace()相对于push()的优势:
//                  速度更快!
//    * q.swap(_q): 交换q和_q的值.

#include <queue>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;
using std::queue;
using std::string;
using std::deque; // <queue>头文件包含了<deque>

/* 借助一系列log函数使核心代码更加整洁 */

void log(const char *msg, const string &val) {
  cout << msg << ": " << val << endl;
}

void log2(const char *msg, const string &val1, const string &val2) {
  cout << msg << ": " << val1 << ", " << val2 << endl;
}

void log3(const char *msg, int val) {
  cout << msg << ": " << val << endl;
}

// Customer类是对string类的一层封装.
// 其特定成员函数在执行时会输出提示信息, 用于跟踪对象的生命周期和使用情况
// 数据成员name被声明在public域, 从而可以由对象直接访问.
class Customer {
public:
  string name_;
  explicit Customer(string name = "null") : name_(name) {
    log("c'tor called", name_);
  }
  Customer(const Customer &c) : name_(c.name_) {
    log("copy c'tor called", name_);
  }
  ~Customer() {
    log("d'tor called", name_);
  }
  Customer &operator=(const Customer &c) {
    log2("assignment", name_, c.name_);
    // 这里不必要添加this==&c的判断代码, 交给string类的operator=运算符函数处理即可.
    name_ = c.name_;
    return *this;
  }
  friend ostream &operator<<(ostream &os, const Customer &c) {
    os << c.name_;
    return os;
  }
};

void log4(const char *msg, const Customer &c) {
  cout << msg << ": " << c.name_ << endl;
}

int main() {
  queue<Customer> line;
  // 比较push()和emplace()的实现细节
  Customer bob("Bob"), caroline("Caroline"), daisy("Daisy"), eric("Eric");
  line.push(bob);
  line.emplace(caroline);
  line.push(daisy);
  line.emplace(eric);
  // 输出结果显示: push()方法并没有创建临时变量再赋值...原因无法理解.
  // 先放一边吧. 毕竟emplace()功能较新, 有待进一步了解.

  log3("queue size", line.size());
  log4("queue front value", line.front());
  log4("queue back value", line.back());
  line.pop();
  log3("queue size after pop()", line.size());
  log4("queue front value after pop()", line.front());

  // queue<int> int_line {1, 2, 3, 4, 5};  // queue不支持列表初始化
  // 因为deque支持列表初始化, 而queue支持用一个deque对象初始化, 因此可以使用如下语句:
  queue<int> int_line(deque<int>{1, 2, 3, 4, 5});
  queue<int> int_line_2(deque<int>{7, 8, 9});
  log3("size of integer queue 1", int_line.size());
  log3("size of integer queue 2", int_line_2.size());
  int_line.swap(int_line_2);
  log3("size of integer queue 1 after swap()", int_line.size());
  log3("size of integer queue 2 after swap()", int_line_2.size());

}