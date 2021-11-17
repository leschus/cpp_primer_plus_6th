#include <iterator> // 提供多种迭代器模板: ostream_iterator, istream_iterator,
                    // reverse_iterator, back_insert_iterator,
                    // front_insert_iterator, insert_iterator
#include <algorithm>  // 提供了copy()函数
#include <iostream>
#include <vector>
#include <list>

using std::copy;
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
using std::reverse_iterator;
using std::back_insert_iterator;
using std::for_each;
using std::list;
using std::front_insert_iterator;
using std::insert_iterator;

void output(const int n) { cout << n << " "; }

int main() {
  cout << "### Testing basic usage of copy().\n";
  vector<int> vec = {1, 2, 3, 4, 5, 6 ,7 ,8};   // 使用列表初始化
  int ints[4] = {4, 3, 2, 1};
  copy(ints, ints + 4, vec.begin());  // 用ints内的元素替换vec开头的内容
  // copy()前两个参数指定要复制的内容(由迭代器类型指定)
  // copy()的第三个参数指明要将复制内容的第一个元素放到什么位置(由迭代器类型指定)
  for (int x: vec) {  // 使用基于范围的for循环
    cout << x << " ";
  } // 预期输出: 4 3 2 1 5 6 7 8
  cout << endl;

  cout << "### Testing ostream_iterator used in copy().\n";
  // 创建一个ostream_iterator迭代器, 并使用copy()来完成向屏幕输出字符的工作
  // 第一个模板参数指明被发送给输出流的数据类型(double)
  // 第二个模板参数指明输出流使用的字符类型(char)
  // 构造函数的第一个参数指定使用的输出流(cout)
  // 构造函数的第二个参数指定输出流中每个数据项之间的分隔符(" ")
  ostream_iterator<double, char> out_iter(cout, " ");
  vector<double> vec2 = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  copy(vec2.begin(), vec2.end(), out_iter);
  cout << endl;
  // 另一种在copy()中使用ostream_iterator的方法: 使用匿名ostream_iterator
  copy(vec2.begin(), vec2.end(), ostream_iterator<double, char>(cout, " "));
  cout << endl;

  cout << "### Testing istream_iterator used in copy().\n";
  // 创建一个istream_iterator, 并使用copy()来完成从键盘读取字符的工作
  // 第一个模板参数指明要读取的数据类型(int)
  // 第二个模板参数指明输入流使用的字符类型(char)
  // 构造函数接收的单一参数指明使用的输入流(cin)
  // 省略构造函数的参数表示输入失败, 可以用于标识输入的结束(碰到文件尾/类型不匹配/其他故障)
  /* {
    istream_iterator<int, char> in_iter(cin);
    // istream_iterator<int, char> in_iter_end();
    // 上述语句, 编译器没有将in_iter_end识别为一个istream_iterator迭代器实例,
    // 难道说, istream_iterator的无参构造函数只是一种特殊标记, 并不能用来创建一个具体的
    // istream_iterator实例?
    // 由此导致地, copy()的第二个参数也不能设置为in_iter_end, 而只能显式地使用
    // istream_iterator<int, char>()的形式
    vector<int> vec3(5); // 创建一个容量为10的空向量
    cout << "Enter integers to initialize vec3: ";
    // copy(in_iter, in_iter_end, vec.begin()); // 出错
    copy(in_iter, istream_iterator<int, char>(), vec3.begin());
    for (int x: vec3) cout << x << " ";
    cout << endl;
  } */
  // 测试表明, 使用预先创建istream_iterator实例再将其作为copy()的参数的方式来
  // 读取输入, 程序会在创建完in_iter实例后就进入等待输入状态, 而不是预想的那样: 在调用
  // copy()函数时才等待用户输入.
  // 为避免出现这种情况, 应该尽量避免预先创建istream_iterator实例, 而是在调用copy()
  // 时再临时创建.
  vector<int> vec3(5); // 创建一个容量为10的空向量
  cout << "Enter integers to initialize vec3: ";
  copy(istream_iterator<int, char>(cin), istream_iterator<int, char>(),
       vec3.begin());
  // 另外需要注意的, ostream_iterator和istream_iterator并不会扩展目标容器的容量,
  // 因此, 如果写入数据后导致目标容器容量超限, 将会引发运行错误
  // 例如, 这里vec3容量为5, 如果istream_iterator通过cin读取了6个整数, 就会导致程序崩溃.
  for (int x: vec3) cout << x << " ";
  cout << endl;

  cout << "### Testing reverse_iterator used in copy().\n";
  // 使用reverse_iterator反向迭代器来倒序输出向量中的元素
  // 怎么创建一个用于vector<int>的reverse_iterator迭代器实例?
  vector<int> vec4 = {1, 3, 5, 7, 9};
  // reverse_iterator<vector<int> > ri(vec4);  // 这样? ==> 不行, 编译不通过
  vector<int>::reverse_iterator ri2;  // 还是这样? ==> OK
  // for (ri2 = vec4.end(); ri2 != vec4.begin(); ri2++) {
  //   cout << *ri2 << " ";
  // } // 由于vec4.end()返回vector<int>::iterator类型, 与ri2类型不匹配,
      //导致上面编译出错. 应该使用rbegin()和rend()成员
  for (ri2 = vec4.rbegin(); ri2 != vec4.rend(); ri2++) {
    cout << *ri2 << " ";
  }
  cout << endl;
  // 使用copy()和ostream_iterator迭代器, 可以不需要显式创建reverse_iterator迭代器就
  // 完成将向量内容逆序输出至屏幕的工作
  ostream_iterator<int, char> out_iter2(cout, " ");
  copy(vec4.rbegin(), vec4.rend(), out_iter2);
  cout << endl;

  // 前述的例子中, 如果copy()的目标容器的容量不够用来存储其接收到的数据, 将会引发运行错误.
  // 通过使用插入迭代器, 可以使得目标容器自动调整容量以容纳新加入的数据.
  // 有三种插入迭代器:
  //    back_insert_iterator将新数据插入到容器尾部(最后一个元素之后)
  //    front_insert_iterator将新数据插入到容器头部(第一个元素之前)
  //    insert_iterator将新数据插入到容器指定元素之前
  cout << "### Testing back_insert_iterator used in copy().\n";
  // 使用限制: back_insert_iterator要求它处理的容器有一个push_back()方法, 即该容器
  // 应当允许在尾部进行快速插入. vector类符合要求.
  int ints2[5] = {2, 4, 6, 8, 10};
  vector<int> vec5;
  // 创建一个具名的back_insert_iterator实例并在copy()中使用
  back_insert_iterator<vector<int> > back_iter(vec5);
  copy(ints2, ints2 + 2, back_iter);
  // 使用for_each搭配output()输出向量元素
  for_each(vec5.begin(), vec5.end(), output);
  cout << endl;
  // 使用匿名的back_insert_iterator实例并在copy()中使用
  copy(ints2 + 2, ints2 + 5, back_insert_iterator<vector<int> >(vec5));
  for_each(vec5.begin(), vec5.end(), output);
  cout << endl;

  cout << "### Testing front_insert_iterator used in copy().\n";
  // 使用限制: front_insert_iterator要求它处理的容器有一个push_front()方法, 即该容器
  // 应当允许在头部进行快速插入. vector类不满足该要求, list类满足.
  // front_insert_iterator执行插入时类似于链表的头插法.
  list<int> l1;
  // 使用具名的front_insert_iterator实例
  front_insert_iterator<list<int> > front_iter(l1);
  copy(ints2, ints2 + 2, front_iter);
  for (int x: l1) { cout << x << " "; } // 使用基于范围的for循环输出l1内容
  cout << endl;
  // 使用匿名的front_insert_iterator实例
  copy(ints2 + 2, ints2 + 5, front_insert_iterator<list<int> >(l1));
  for (int x: l1) { cout << x << " "; }
  cout << endl;

  cout << "### Testing insert_iterator used in copy().\n";
  // 注: insert_iterator没有像前两者那样的使用限制. 在创建insert_iterator实例时,
  // 需要用构造函数的第二个参数指示插入位置.
  vector<int> vec6 = {100, 200, 300, 400, 500};
  // 使用具名的insert_iterator实例
  insert_iterator<vector<int> > ins_iter(vec6, vec6.begin() + 2);
  copy(ints2, ints2 + 2, ins_iter);
  for_each(vec6.begin(), vec6.end(), output);
  cout << endl;
  // 使用匿名的insert_iterator实例
  copy(ints2 + 2, ints2 + 5,
       insert_iterator<vector<int> >(vec6, vec6.begin() + 2));
  for_each(vec6.begin(), vec6.end(), output);
  cout << endl;
  // 另: 注意比较front_insert_iterator<A>(a)和insert_iterator<A>(a, a.begin())的
  // 的区别. 在copy()中使用它们时, 前者类似于头插法, 目标容器中的元素顺序将与插入序列的顺序
  // 相反, 而后者的效果则是目标容器中的元素顺序和插入序列的顺序相同.
}

/*
测试输出:

### Testing basic usage of copy().
4 3 2 1 5 6 7 8
### Testing ostream_iterator used in copy().
1.1 2.2 3.3 4.4 5.5 6.6
1.1 2.2 3.3 4.4 5.5 6.6
### Testing istream_iterator used in copy().
Enter integers to initialize vec3: 1 2 3 ^Z
1 2 3 0 0
### Testing reverse_iterator used in copy().
9 7 5 3 1
9 7 5 3 1
### Testing back_insert_iterator used in copy().
2 4
2 4 6 8 10
### Testing front_insert_iterator used in copy().
4 2
10 8 6 4 2
### Testing insert_iterator used in copy().
100 200 2 4 300 400 500
100 200 6 8 10 2 4 300 400 500

*/