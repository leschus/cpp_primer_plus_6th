// 判断回文串
// 进阶版本. 要求能够处理包含空白字符, 大小写字母及标点符号的字符串.
// 处理方式:
//      1. 忽略字符串中的所有非字母的字符
//      2. 不区分大小写

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

bool is_palindrome(const string &s);

bool is_not_alpha(char c) { return !isalpha(c); }
char to_lower(char c) { return tolower(c); }

int main() {
  string str;
  cout << "Enter a string, or type [Ctrl-Z] to quit: ";
  // 由于现在接收的字符串中可能存在空白字符, 因此不能再用cin>>str读取输入
  while (getline(cin, str)) {
    if (str.empty()) continue;  // 忽略空串
    if (is_palindrome(str))
      cout << "It's a palindrome.\n";
    else
      cout << "Not a palindrome.\n";
    cout << "Enter another string, or type [Ctrl-Z] to quit: ";
  }
  cout << "Bye.\n";
}


bool is_palindrome(const string &s) {
  // 注意: s为const类型, 因此不能就地删除. 可以创建一个s的副本进行操作
  string s_copy(s);

  // 删除s_copy中的所有非字母字符
  auto pos = remove_if(s_copy.begin(), s_copy.end(), is_not_alpha);
  // 注意: 这里is_not_alpha()接收的是char类型参数, 如此才能与string中保存的char匹配.
  // 如果和isalpha()一样接收int参数, 将会编译报错.

  // 注意: remove_if()不是成员函数, 因此不能调整s_copy的size. 它将没被删除的字符放在
  // s_copy内部char数组的开始位置, 并返回一个指向新的超尾值的迭代器. 要借助该迭代器来修改
  // s_copy的size. 一般来说, 可以使用erase()方法来删除一个区间, 但因为string的erase方法
  // 每次只能删除单个元素, 因此这里使用了获取s_copy的子串再将其赋给s_copy的方式来更新s_copy.
  s_copy = s_copy.substr(0, pos - s_copy.begin());

  // 将s中的大写字母全部改为小写
  // transform(s_copy.begin(), s_copy.end(), s_copy.begin(), to_lower);
  transform(s_copy.begin(), s_copy.end(), s_copy.begin(), to_lower);
  // 需对tolower()也进行一层包装, 接收一个char类型参数, 以避免类型不匹配导致编译出错

  // 下面的操作和palindrome_check.cc中的方法1相同
  string t;
  reverse_copy(s_copy.begin(), s_copy.end(),
              insert_iterator<string>(t, t.begin()));
  return s_copy == t;
}