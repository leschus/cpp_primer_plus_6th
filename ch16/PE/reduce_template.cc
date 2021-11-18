// 将reduce.cc中的reduce()函数改造为模板函数:
//    template <typename T>
//    int reduce(T ar[], int n);

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
int reduce(T ar[], int n) {
  // 内部实现竟然和非模板函数版本一模一样, 这得益于STL函数的通用性
  sort(ar, ar + n);
  return unique(ar, ar + n) - ar;
}

template <typename T>
void show(T ar[], int n) {
  for (int i = 0; i < n; i++) {
    cout << ar[i] << " ";
  }
  cout << endl;
}

int main() {
  long nums[10] = {10, 8, 8, 2, 2, 5, 6, 7, 7, 9};
  string strs[8] = {"aaa", "acd", "xyz", "zyx", "abc", "aaa", "xyz", "lmn"};
  int n_new;
  n_new = reduce(nums, 10);
  show(nums, n_new);
  n_new = reduce(strs, 8);
  show(strs, n_new);
}