// Mat和Pat邀请朋友来参加聚会

#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

void Set(set<string> &s);
void Show(const set<string> &s);

int main() {
  // 选用set而不是list来保存朋友姓名的原因:
  //    * set在插入元素后自动排序.
  //    * 可以使用set_union()方便地完成合并两个姓名集合同时删除重复元素的工作.
  //    * list需要在插入完所有元素后手动进行一次排序
  //    * list的merge()方法不会删除重复元素
  set<string> mat_set, pat_set, common_set;
  cout << "Enter Mat's friends' names:\n";
  Set(mat_set);
  Show(mat_set);
  cout << "Enter Pat's friends' names:\n";
  Set(pat_set);
  Show(pat_set);
  set_union(mat_set.begin(), mat_set.end(), pat_set.begin(), pat_set.end(),
            insert_iterator<set<string> >(common_set, common_set.begin()));
  Show(common_set);
  cout << "Done.\n";
}

void Set(set<string> &s) {
  string tmp;
  while (getline(cin, tmp)) {
    if (tmp.empty())
      break;    // 读取到空行时结束
    s.insert(tmp);
  }
}

void Show(const set<string> &s) {
  cout << "set content:\n";
  for (string e: s) cout << "  " << e << endl;
}