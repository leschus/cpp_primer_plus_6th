#include <iostream>
#include "golf.h"

Golf::Golf(const char *name, int hc) {
  int i = 0;
  // while循环按序拷贝name中的字符到g.fullname中
	// 当字符串name的长度超过Len-1时, 将只拷贝前Len-1个字符至
	// g.fullname中, 多出的字符被截断
  // (也可直接调用strncpy(filename_, name, kLen-1)完成该功能)
	while (i < kLen_ - 1 && name[i])
	{
		fullname_[i] = name[i];
		i++;
	}
  fullname_[i] = '\0';

  handicap_ = hc;
}

int Golf::SetGolf() {
  using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter the fullname: " << endl;
	char name[kLen_];
	char next;
	cin.get(name, kLen_);
	if(cin) { // true, 说明没有输入空行
		cin.get(next);
		while(next != '\n') { // 丢弃缓冲区中可能存在的剩余字符
			cin.get(next);
		}

		cout << "Enter the handicap: " << endl;
		int hc;
		cin >> hc;

		*this = Golf(name, hc); // 调用构造函数并将创建的Golf对象赋给*this

    // 有必要加上这句, 因为输入hc之后换行符留在缓冲区, 会导致下次设置name时读到
		// 该换行符继而仍未用户输入了空串导致函数直接返回0结束
		cin.get(next);
		return 1;
	}
  // 至于这里就没必要加这句了, 因为cin.get(char*, int)读到空行之后, 程序逻辑就此结束.
	// 如果说不看程序逻辑, 后续要继续使用cin处理输入的话, 这里就需要添加该句, 且要用
  // cin.clear()重置输入流
	// cin.get(next);

	return 0; // 当name是空字符串时, 返回0
}

void Golf::set_handicap(int hc) {
  handicap_ = hc;
}

void Golf::Show() {
  std::cout << fullname_ << ": " << handicap_ << std::endl;
}