#include <iostream>
#include <iterator>
#include <algorithm>    // for transform()
// #include <functional>

//  transform()函数是一个典型的接收函数对象作为参数的STL函数, 它有一个接收一元函数作为最后
// 一个参数的版本, 也有一个接收二元函数作为最后一个参数的版本.

using std::transform;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::multiplies;
using std::cin;

int plus_one(const int &n) { return n + 1; }

class PlusN {
 public:
  PlusN(int n = 1) : n_(n) {}
  int operator()(const int x) const { return x + n_; }
 private:
  int n_;
};

int main() {
  int nums1[6] = {1, 3, 5, 7, 9, 11};
  int nums2[6] = {1, -1, 1, -1, 1, -1};
  ostream_iterator<int, char> out_iter(cout, " ");
  // 接收一个一元函数plus_one, 对nums1中的所有元素执行操作, 并将结果输出至屏幕
  transform(nums1, nums1 + 6, out_iter, plus_one);
  cout << endl;
  // 也可以进行就地更新: 将第三个参数设置成和第一个参数相同
  transform(nums1, nums1 + 6, nums1, plus_one);
  for (int x: nums1) cout << x << " ";
  cout << endl;
  // 接收一个二元函数multiplies<int>, 将nums1和nums2中对应位置的元素相乘, 结果输出至屏幕
  transform(nums1, nums1 + 6, nums2, out_iter, multiplies<int>());
  cout << endl;
  // 也可以就地更新: 将第四个参数设置成和第一个或第三个参数相同
  transform(nums1, nums1 + 6, nums2, nums1, multiplies<int>());
  for (int x: nums1) cout << x << " ";
  cout << endl;

  //  下面考虑一种情况: 如果要将plus_one函数改造成plus_n, 即该函数将传入参数加上另一个参数
  // n作为函数返回值, 而不是像原先那样固定只加一. 该如何实现?
  //  要注意到, 仍需要确保plus_n是一个一元函数, 因此不可将n添加为函数的入口参数.
  //  解决方案是, 设计一个类, 将n值作为类数据成员, 并为类重载()运算符函数, 该函数接收一个
  // 参数, 保证了一元性, 而在使用类对象调用该运算符函数时, 由于成员函数可以访问类数据成员n,
  // 因此就相当于将n间接地传给了该函数, 从而达到了目的. 详情见类定义PlusN.
  //  使用时, 先以n为参数创建一个PlusN对象, 再将对象作为transform()的最后一个参数. 也可以
  // 直接在transform()调用语句中创建匿名对象.
  int n;
  cout << "input n: ";  // 由用户确定n值
  cin >> n;
  transform(nums1, nums1 + 6, out_iter, PlusN(n));  // 将nums1所有元素加上n,
                                                    // 结果输出至屏幕

}