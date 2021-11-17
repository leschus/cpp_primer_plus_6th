// forward_list, 前向列表, C++11新增.
// 实际上就是一个单链表.

#include <forward_list>
#include <string>
#include <iostream>
#include <algorithm>    // for find(), copy()
#include <iterator>

using std::forward_list;
using std::string;
using std::cout;
using std::endl;
using std::find;
using std::copy;
using std::ostream_iterator;

int main() {
  string str[5] = {"apple", "bear", "cat", "date", "exotic"};
  // 通过一对输入迭代器来初始化forward_list
  forward_list<string> simplelist(str, str + 5);
  ostream_iterator<string, char> out_iter(cout, " ");
  copy(simplelist.begin(), simplelist.end(), out_iter);
  cout << endl;
  // 在cat的后面插入fish
  // 使用find()定位cat的位置
  auto pos = find(simplelist.begin(), simplelist.end(), "cat");
  // 使用insert_after()插入新元素
  pos = simplelist.insert_after(pos, "fish");
  cout << "after insert, pos points to \"" << *pos << "\"\n";
  copy(simplelist.begin(), simplelist.end(), out_iter);
  cout << endl;
  // 删除date的后继
  // 使用find()定位date的位置
  pos = find(simplelist.begin(), simplelist.end(), "date");
  // 使用erase_after()删除date的后继
  pos = simplelist.erase_after(pos);  // 删除操作耗时O(1)
  if (pos == simplelist.end()) {
    cout << "Now pos points to end().\n";
  }
  copy(simplelist.begin(), simplelist.end(), out_iter);
  cout << endl;
  // 另一种删除单个元素的方式: remove -- 删除指定值的所有元素
  simplelist.remove("date");  // 耗时O(n)
  copy(simplelist.begin(), simplelist.end(), out_iter);
  cout << endl;
}