// 判断回文串
//  这个一个简单版本: 不考虑大小写字母/空白字符/标点符号等, 可以认为处理的都是小写的单个单词,
// 如: otto, onion等

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_palindrome(const string &s);

int main() {
  string str;
  cout << "Enter a string, or type [Ctrl-Z] to quit: ";
  while (cin >> str) {
    if (is_palindrome(str))
      cout << "It's a palindrome.\n";
    else
      cout << "Not a palindrome.\n";
    cout << "Enter another string, or type [Ctrl-Z] to quit: ";
  }
  cout << "Bye.\n";
}

bool is_palindrome(const string &s) {
  // 方法1: 使用reverse_copy()...OK
  string t;
  reverse_copy(s.begin(), s.end(), insert_iterator<string>(t, t.begin()));
  // 上一句为什么使用基于t.begin()创建的insert_iterator而非直接使用t.begin()作为
  // reverse_copy()的第三个参数? ==> 参见string_reverse.cc中的解释.
  return s == t;

  // 方法2: 不借助STL...OK
  // int i, j;
  // for (i = 0, j = s.length() - 1; i < j; i++, j--) {
  //   if (s[i] != s[j])
  //     break;
  // }
  // return i >= j;
}