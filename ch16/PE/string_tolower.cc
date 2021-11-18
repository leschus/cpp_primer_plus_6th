// string保存一个英文单词, 现要将单词小写化

// 使用STL中的transform()函数和cctype中的tolower()函数

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

char toLower(char c) { return tolower(c); }

int main() {
  string str = "China";
  transform(str.begin(), str.end(), str.begin(), toLower);
  cout << str << endl;
}