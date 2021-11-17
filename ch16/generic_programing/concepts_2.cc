// 序列(sequence), 针对容器概念的一种改进

// 序列容器包括: deque, list, queue, priority_queue, stack, vector,
//             forward_list (C++11新增)
// array类也被归为序列容器, 尽管它不满足序列的部分要求

// 序列容器的共性要求: 包括一系列构造方法, 一系列insert()和erase()方法, 以及clear()方法
// 序列容器的可选要求(即只有部分序列容器类型提供支持):
//    包括front(), back(), push_front(), pop_front(), push_back(), pop_back(),
//    []运算符重载以及at()方法等.

// 可反转容器(reversible container)是另一种针对容器概念的改进
// 一般提供rbegin()和rend()两个方法, 分别返回一个指向反转序列第一个元素的迭代器和反转序列
// 的超尾迭代器. 这两种迭代器类型都是reverse_iterator----(定义在<iterator>头文件, 包含
// 于名字空间std中的一种迭代器类型)

// list序列容器的特有方法:
//    由于list基于链表实现, 其提供了若干与链表操作相关的方法.
//    包括: merge(), 用于两个链表
//         remove(), 用于从链表中删除所有值为特定值的所有元素
//         sort(), 使用<运算符对链表进行排序
//         splice(), 将一个链表插入到当前链表指定位置的前面
//         unique(), 将链表中连续的相同元素压缩为单个元素

// 下面对上述的各种特性进行测试, 验证其功能.

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::for_each;
using std::vector;
using std::deque;
using std::is_sorted;


// 与concepts.cc类似, 提供一个Demo结构体作为序列容器储存的元素类型
struct Demo {
  string str;
  Demo(const string &s = "empty") : str(s) {
    cout << str << ": c'tor called.\n";
  }
  ~Demo() { cout << str << ": d'tor called.\n"; }
  Demo(const Demo &demo) : str(demo.str) {
    cout << str << ": copy c'tor called.\n";
  }
  bool operator<(const Demo &demo) const {
    return str < demo.str;
  }
  bool operator==(const Demo &demo) const {
    return str == demo.str;
  }
};

// 用作for_each()的第三个参数
void print(const Demo &demo) {
  cout << "(" << demo.str << ") ";
}

int main() {
  {
    cout << "\n### Testing different types of c'tor.\n";
    // 测试几种不同的序列容器独有的构造方式, 以list为例
    Demo atom("atom");
    list<Demo> many_atoms(4, atom); // 构造一个包含4个元素的序列, 每个元素值均为atom
    for_each(many_atoms.begin(), many_atoms.end(), print);
    cout << endl;
    auto p_more_atoms = new list<Demo>(2, atom);  // 同上, 但创建匿名序列
    for_each(p_more_atoms->begin(), p_more_atoms->end(), print);
    cout << endl;
    delete p_more_atoms;
    // 声明一个具名序列, 将其初始化为区间[a, b)的内容
    // 区间[a, b)通过迭代器给出. 但不能像下面这样(这种用一个已有的序列容器初始化新序列的操作
    // 更像是拷贝构造函数该干的事):
    // list<Demo> copy_atoms(many_atoms.begin(), many_atoms.begin() + 2);// error
    Demo fruits[] {Demo("apple"), Demo("banana"), Demo("cherry")};
    // 可以像下面这样
    list<Demo> copy_fruits(fruits, fruits + sizeof(fruits) / sizeof(Demo));
    for_each(copy_fruits.begin(), copy_fruits.end(), print);
    cout << endl;
    // 同样的方法, 可用于创建匿名序列
    auto p_less_fruits = new list<Demo>(fruits, fruits + 2);
    for_each(p_less_fruits->begin(), p_less_fruits->end(), print);
    cout << endl;

    cout << "\n### Testing different types of insert().\n";
    Demo date("date");
    // 将单个元素插入到序列中的某个位置(由第一个参数指定)
    copy_fruits.insert(copy_fruits.end(), date);
    for_each(copy_fruits.begin(), copy_fruits.end(), print);
    cout << endl;
    Demo lemon("lemom");
    // 将一个元素的多个复制插入到序列中的某个位置(由第一个参数指定)
    copy_fruits.insert(copy_fruits.begin(), 2, lemon);
    for_each(copy_fruits.begin(), copy_fruits.end(), print);
    cout << endl;
    Demo new_fruits[] {Demo("olive"), Demo("peach"), Demo("watermelon")};
    // 将一个区间(由两个迭代器指定)中的元素插入到序列某个位置(由第一个参数指定)
    copy_fruits.insert(copy_fruits.end(), new_fruits, new_fruits + 3);
    for_each(copy_fruits.begin(), copy_fruits.end(), print);
    cout << endl;

    cout << "\n### Testing different types of erase().\n";
    // 删除序列中某个元素(由迭代器指定)
    copy_fruits.erase(copy_fruits.begin()); // 删除第一个元素
    for_each(copy_fruits.begin(), copy_fruits.end(), print);
    cout << endl;
    // 删除序列中某个区间(由两个迭代器指定)中的所有元素
    // 注意: 序列概念要求迭代器至少是正向迭代器. 因此不能通过下面的语句达到删除序列最后三个
    // 元素的目的(编译出错).
    // copy_fruits.erase(copy_fruits.rbegin(), copy_fruits.rbegin() + 3);
    // 同样, 也不能使用下面的语句. 因为迭代器不支持减法运算
    // copy_fruits.erase(copy_fruits.end() - 3, copy_fruits.end());
    // 换成下面的写法, 依旧不行. 究其根本, 是因为list基于链表实现, 不支持随机访问, 只能够
    // 顺序访问.
    // copy_fruits.erase(copy_fruits.begin() + (copy_fruits.size() - 3),
    //                   copy_fruits.end());
    // 因此, 下面考虑使用支持随机访问的vector序列容器进行测试:
    vector<Demo> basket(fruits, fruits + 3);  // 先往篮子里装水果
    basket.insert(basket.end(), new_fruits, new_fruits + 3);  // 再装点
    for_each(basket.begin(), basket.end(), print);
    cout << endl;
    // 使用erase()从篮子里取出最后的三个水果:
    // basket.erase(basket.rbegin(), basket.rbegin() + 3); // Error
    // 上一句不可行, 原因在于erase()仅支持正向迭代
    basket.erase(basket.end() - 3, basket.end());   // OK
    // 上一句可行, 说明导致上文中对copy_fruits执行区间删除的后两次尝试均失败的原因就是在
    // 于list不支持随机访问.
    for_each(basket.begin(), basket.end(), print);
    cout << endl;
    // 取出篮子里剩余的所有水果: 使用clear()方法
    basket.clear();
    if (basket.empty()) cout << "Now basket is empty.\n";

    cout << "\n### Testing optional functions of sequence containers.\n";
    // 测试类型为vector, list和deque
    // 依次创建对应类型的一个对象, 使用new_fruits数组初始化
    vector<Demo> vec(new_fruits, new_fruits + 3);
    list<Demo> lis(new_fruits, new_fruits + 3);
    deque<Demo> deq(new_fruits, new_fruits + 3);
    for_each(vec.begin(), vec.end(), print);
    cout << endl;
    for_each(lis.begin(), lis.end(), print);
    cout << endl;
    for_each(deq.begin(), deq.end(), print);
    cout << endl;
    // front()方法
    cout << "front() tests:\n";
    print(vec.front());
    print(lis.front());
    print(deq.front());
    // back()方法
    cout << "\nback() test:\n";
    print(vec.back());
    print(lis.back());
    print(deq.back());
    // push_front()方法
    cout << "\npush_front() tests:\n";
    // Demo pear("pear");
    // vec.push_front(pear); // Error
    lis.push_front(Demo("pear"));
    deq.push_front(Demo("pear"));
    // push_back()方法
    cout << "push_back() tests:\n";
    cout << "before push_back(): " << vec.capacity() << endl; // 3
    vec.push_back(Demo("pear"));
    cout << "after push_back(): " << vec.capacity() << endl;  // 6
    // 输出结果中, 上述语句触发了对vec中原有元素的拷贝构造. 原因应该是向vec中插入pear
    // 触发了vector容器的自动扩容机制. 通过比较调用push_back()前后的capacity()值可以
    // 确认: 第一次调用前, capacity为3, 第一次调用后, capacity为6, 再一次调用, 由于
    // capacity未满, 从而没有扩容, capacity仍为6.
    vec.push_back(Demo("apple"));
    cout << "after another push_back(): " << vec.capacity() << endl;  // 6
    // 出于同样的原因, 下面的语句也会触发对序列容器中原有元素的拷贝构造.
    lis.push_back(Demo("pear"));
    deq.push_back(Demo("pear"));
    // pop_front()方法, 注意: 该函数不带参数
    cout << "pop_front() tests:\n";
    // vec.pop_front();      // Error
    lis.pop_front();
    deq.pop_front();
    // pop_back()方法, 注意: 该函数不带参数
    cout << "pop_back() tests:\n";
    vec.pop_back();
    lis.pop_back();
    deq.pop_back();
    for_each(vec.begin(), vec.end(), print);
    cout << endl;
    for_each(lis.begin(), lis.end(), print);
    cout << endl;
    for_each(deq.begin(), deq.end(), print);
    cout << endl;
    // []运算符重载
    cout << "operator[] tests:\n";
    print(vec[0]);
    // print(lis[0]);        // Error
    print(deq[0]);
    // at()方法
    cout << "\nat() tests:\n";
    print(vec.at(0));
    // print(lis.at(0));     // Error
    print(deq.at(0));
    cout << endl;

    cout << "\n### Testing additional functions for list.\n";
    // a.merge(b), 将链表b与调用链表a合并, 要求合并前两个链表都已经排序.
    // 合并后的链表保存在a中, 而b成为空表.
    // a.sort(), 使用<运算符对链表元素进行排序
    list<Demo> lastlist = {Demo("China"), Demo("USA"), Demo("Russia")};
    list<Demo> restlist = {Demo("India"), Demo("South Africa"), Demo("Brazil")};
    lastlist.sort();
    restlist.sort();
    for_each(lastlist.begin(), lastlist.end(), print);
    cout << endl;
    for_each(restlist.begin(), restlist.end(), print);
    cout << endl;
    if (is_sorted(lastlist.begin(), lastlist.end()) &&
        is_sorted(restlist.begin(), restlist.end())) {
      cout << "Both lists are sorted.\n";
      lastlist.merge(restlist);
      for_each(lastlist.begin(), lastlist.end(), print);
      cout << endl;
      // 上面的输出结果有序, 说明merge()会将两个有序链表合并为一个有序链表
      if (restlist.empty()) {
        cout << "Now restlist is empty.\n";
      }
    }
    // a.remove(t), 删除链表a中所有t的实例
    Demo brazil("Brazil");
    lastlist.push_back(brazil);
    for_each(lastlist.begin(), lastlist.end(), print);
    cout << endl;
    lastlist.remove(brazil);
    for_each(lastlist.begin(), lastlist.end(), print);
    cout << endl;
    // a.splice(pos, b), 将链表b插入到链表a的位置p的前面
    // 插入完成后, b成为空表
    restlist.push_back(Demo("Denmark"));
    restlist.push_back(Demo("Germany"));
    // lastlist.splice(lastlist.begin() + 1, restlist);  // 注意: list不支持加法
    lastlist.splice(++lastlist.begin(), restlist);  // list支持自增
    // 上面的语句将Denmark, Germany插入到China之后, Inidia之前, 从而插入完成后不会
    // 破坏lastlist的有序性
    for_each(lastlist.begin(), lastlist.end(), print);
    cout << endl;
    if (restlist.empty()) {
      cout << "Now restlist is empty again.\n";
    }
    // a.unique(), 将链表a中的连续相同元素压缩为单个元素
    list<int> simplelist {1, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7};
    simplelist.unique();
    for(int x: simplelist) {
      cout << x << " ";
    }
    cout << endl;
    // Tips: 通常可以将sort()和unique()搭配使用, 用于删除链表中的重复元素

    cout << "\n### End of inner block.\n";
  }
  cout << "Done.\n";
  return 0;
}