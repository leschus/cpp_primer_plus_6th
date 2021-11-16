// 容器概念
// 使用set类为例, 对基本的容器特征进行测试

// C++11以前的容器类:
//    deque, list, queue, priority_queue, stack, vector, map, multimap, set,
//    multiset, bitset
// C++11新增的容器类:
//    forward_list, unordered_map, unordered_multimap, unordered_set,
//    unordered_multiset
// 另外, C++11不再将bitset视作容器, 而是一个独立的类别

#include <iostream>
// #include <vector>
#include <set>
#include <string>
#include <memory>     // for unique_ptr
#include <algorithm>  // for for_each

using std::cout;
using std::endl;
// using std::vector;
using std::set;
using std::string;
using std::unique_ptr;
using std::for_each;

struct Demo {
  string str;
  int num;
  Demo() : str("empty"), num(0) {
    cout << "default c'tor called.\n";
  }
  Demo(const string &s, int n) : str(s), num(n) {
    cout << str << ", " << num << ": c'tor called.\n";
  }
  ~Demo() { cout << str << ", " << num << ": d'tor called.\n"; }
  bool operator==(const Demo &demo) const {
    // 注意函数头里有两个const, 都得加, 否则编译报错
    return str == demo.str && num == demo.num;
  }
  Demo(const Demo &demo) : str(demo.str), num(demo.num) {
    cout << str << ", " << num << ": copy c'tor called.\n";
  }
  const Demo & operator=(const Demo &demo) {
  // 赋值运算符的返回值需要指明为const吗? 对于a=b=c这样的赋值方式, 加不加都行.
  // 对于(a=b)=c这样的赋值方式, 不能加const; 或者可通过加const来禁止(a=b)=c
  // 这样的赋值方式.
    cout << "assignment: " << str << ", " << num
         << " <== " << demo.str << ", " << demo.num << endl;
    if (this == &demo)
      return *this;
    str = demo.str;
    num = demo.num;
    return *this;
  }
  bool operator<(const Demo &demo) const {
    // 由于set内部要进行自动排序, 因此要提供<比较运算符
    // 注意: 函数头中两个const都是必要的
    if (str < demo.str) return true;
    else if (str > demo.str) return false;
    else if (num < demo.num) return true;
    else return false;
  }
};

// 用作for_each()的第三个参数
void print(const Demo &demo) {
  cout << demo.str << ", " << demo.num << endl;
}

int main() {
  {
    set<Demo> set0 = {  // 使用列表初始化(C++11提供支持)
      Demo("first", 1),
      Demo("second", 2),
      Demo("third", 3)
    };
    // 列表初始化首先对调用构造函数创建三个临时Demo, 再调用拷贝构造函数将每个临时Demo依次
    // 复制到set<Demo>中.

    // 获得一个迭代器, 其满足正向迭代器的任何需求
    // 通过指向第一个元素的迭代器和超尾迭代器来完成容器的遍历工作
    set<Demo>::iterator iter;
    for (iter = set0.begin(); iter != set0.end(); iter++)
      cout << (*iter).str << ", " << (*iter).num << endl;

    // 使用X::value_type获得存储在容器中的对象类型
    set<Demo>::value_type value("hello", 100);

    // 创建具名的空容器
    set<Demo> has_name;
    // 创建匿名的空容器, 由一个unique_ptr指向, 用到了自动类型推断: auto
    auto p_noname = unique_ptr<set<Demo> >(new set<Demo>());
    p_noname.release();

    // 使用拷贝构造函数
    set<Demo> old;
    set<Demo> newly(old);
    set<Demo> newlly = old;  // 效果和上一句相同

    // 使用赋值运算符
    set<Demo> yesterday = {Demo("day", -1)};
    set<Demo> today;
    today = yesterday;

    // 获得容器内的元素个数
    // 对容器中的每个元素应用析构函数: 这应该是是STL实现容器的析构函数时所使用的一种内置操作
    // 尽量避免在代码里用这种方式手动对容器内元素执行析构, 因为这会导致容器过期时执行析构函数
    // 对已析构的元素进行二次析构.
    set<Demo> several_demos = {
      Demo("a", -1), Demo("b", 0), Demo("c", 1)
    };
    cout << several_demos.size() << endl;
    // (&several_demos)->~set<Demo>();
    // 这里注释掉上面这句, 否则程序退出前自动执行析构会出现错误
    // cout << several_demos.size() << endl;
    // 上一句测试表明: 手动执行析构函数后, 容器的size()没有变化

    // 交换两个容器的内容: x.swap(y)
    set<Demo> x = {
      Demo("a", 1), Demo("b", 2)
    };
    set<Demo> y = {
      Demo("m", -1), Demo("n", -2)
    };
    x.swap(y);
    cout << "Contents of x:\n";
    for_each(x.begin(), x.end(), print);
    cout << "Contents of y:\n";
    for_each(y.begin(), y.end(), print);

    // ==运算符
    // `a == b`为真, 当且仅当a和b的长度相同, 且a, b中相应位置的元素对应相等(==)
    // !=运算符: `a != b`等价于`!(a == b)`
    // 注: 要求存储类型定义了==运算符
    if (today == yesterday) cout << "today equals to yesterday.\n";
    if (x != y) cout << "x not equals to y.\n";
  } // 本代码块结束时, 内部创建的容器将自动调用析构函数释放分配的空间
  cout << "Done.\n";
  return 0;
}