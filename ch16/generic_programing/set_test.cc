//  关联容器(associative container), 保存的是"键-值"对
//  set, 是最简单的关联容器. 键和值一一对应, 且键和值等同
// 因此, set其实就是同类型的无重复元素的集合.
//
// 一些常用于处理集合的STL算法函数:
//    * 求并集: set_union()
//    * 求交集: set_intersection()
//    * 求差集: set_difference()
// 另外, 利用upper_bound()和lower_bound()函数可以方便地得到set中处于某个区间中的元素:
//    * lower_bound(): 将键作为参数返回一个迭代器, 该迭代器指向集合中第一个不小于键参数
//    的成员.
//    * upper_bound(): 将键作为参数返回一个迭代器, 该迭代器指向集合中第一个大于键参数的
//    成员.

#include <set>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::set;
using std::set_union;
using std::set_intersection;
using std::set_difference;
using std::copy;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::insert_iterator;

const int kSize = 10;

int main() {
  // 生成kSize个0到100的随机数保存在int数组中
  int nums[kSize];
  srand(time(0));
  for (int i = 0; i < kSize; i++) {
    nums[i] = rand() % 101;
  }
  // 将随机数保存在一个set中
  set<int> numset(nums, nums + kSize);
  // 使用迭代器输出set的所有元素, 可以发现set内部自动将元素排序了. (默认按升序排列)
  ostream_iterator<int, char> out_iter(cout, " ");
  cout << "numset content: \n";
  copy(numset.begin(), numset.end(), out_iter);
  cout << endl;
  // set是可反转容器, 即它提供rbegin()和rend()方法
  cout << "numset content (reversed):\n";
  copy(numset.rbegin(), numset.rend(), out_iter);
  cout << endl;

  // 下面测试求并集/交集/差集的STL函数
  // 用同样的方法创建另外一个包含随机整数的set
  int nums2[kSize];
  for (int i = 0; i < kSize; i++) {
    nums2[i] = rand() % 101;
  }
  set<int> numset2(nums2, nums2 + kSize);
  cout << "numset2 content:\n";
  copy(numset2.begin(), numset2.end(), out_iter);
  cout << endl;
  //  set_union()函数的第五个参数是输出迭代器, 将它设置为ostream_iterator从而将执行结果
  // 输出到屏幕或文件, 也可将其设置为insert_iterator从而将执行结果保存在另一个set中.
  cout << "set_union result:\n";
  set_union(numset.begin(), numset.end(), numset2.begin(), numset2.end(),
            out_iter);
  cout << endl;
  set<int> result;
  set_union(numset.begin(), numset.end(), numset2.begin(), numset2.end(),
            insert_iterator<set<int> >(result, result.begin()));
  cout << "*set_union result:\n";
  copy(result.begin(), result.end(), out_iter);
  cout << endl;
  // 同样的方式, 测试set_intersetcion()
  cout << "set_intersection result:\n";
  set_intersection(numset.begin(), numset.end(), numset2.begin(), numset2.end(),
                   out_iter);
  cout << endl;
  // 测试set_difference()
  cout << "set_difference result:\n";
  set_difference(numset.begin(), numset.end(), numset2.begin(), numset2.end(),
                 out_iter);
  cout << endl;

  // 测试lower_bound()和upper_bound()的使用
  cout << "number(s) in [20, 50] in numset:\n";
  copy(numset.lower_bound(20), numset.upper_bound(50), out_iter);
  cout << endl;
}

/*
某一次测试输出:

numset content:
30 34 36 39 54 58 71 89
numset content (reversed):
89 71 58 54 39 36 34 30
numset2 content:
0 31 32 34 35 43 46 54 94 97
set_union result:
0 30 31 32 34 35 36 39 43 46 54 58 71 89 94 97
*set_union result:
0 30 31 32 34 35 36 39 43 46 54 58 71 89 94 97
set_intersection result:
34 54
set_difference result:
30 36 39 58 71 89

*/