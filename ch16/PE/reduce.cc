// 编写一个老式风格接口的函数:
//    int reduce(long ar[], int n);
// 对长度为n的long数组进行排序, 删除重复的值, 返回缩减后的数组长度
// 借助STL函数实现

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int kRange = 20;

int reduce(long ar[], int n);

void set(long ar[], int n);         // 设置数组
void show(const long ar[], int n);  // 打印数组内容

int main() {
  int n;
  long *p_nums;
  srand(time(0));
  cout << "Enter length of array: ";
  if (cin >> n && n > 0) {
    p_nums = new long[n];
    set(p_nums, n);
    show(p_nums, n);
    int n_new = reduce(p_nums, n);
    // 注意, reduce之后, 数组长度缩减至n_new, 不再是n.
    // 应避免再去访问原先处于数组下标n_new到n之间的元素.
    show(p_nums, n_new);
  }
  cout << "Done.\n";
}

void set(long ar[], int n) {
  for (int i = 0; i < n; i++) {
    ar[i] = rand() % (kRange + 1); // 使用[0, kRange]中的随机整数填充数组
  }
}

void show(const long ar[], int n) {
  for (int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

int reduce(long ar[], int n) {
  sort(ar, ar + n);
  return unique(ar, ar + n) - ar;
  // unique()返回一个指向更新后的数组超尾的指针, 将该值减去数组起始地址得到的就是更新后的
  // 数组长度
}