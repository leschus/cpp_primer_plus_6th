// 反转一个string字符串的方法

// algorithm中提供了reverse()和reverse_copy()方法

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
  string s = "hello, world";
  // 使用reverse()就地反转
  // reverse(begin(s), end(s));  // OK
  reverse(s.begin(), s.end());  // another way
  cout << s << endl;

  // 使用reverse_copy()将反转结果保存在另外一个string对象
  string t;
  // 不能使用t.begin()作为reverse_copy()的第三个参数.
  // 因为reverse_copy()执行的是复制而非插入, 它要求目标容器事先具备足够的空间, 而t初始
  // 情况下为空串, 不够接收从s复制来的字符.
  // 这种情况下, 要将复制转为插入, 即改用insert_iterator模板.
  // reverse_copy(s.begin(), s.end(), t.begin());
  reverse_copy(s.begin(), s.end(), insert_iterator<string>(t, t.begin()));
  cout << t << endl;

}