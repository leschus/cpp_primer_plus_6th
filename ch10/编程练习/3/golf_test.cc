#include <iostream>
#include "golf.h"

const int kSize = 3;

int main() {
  Golf members[kSize];
	int i = 0, ret_val;
	do {
    std::cout << ">>> Turn #" << i + 1 << std::endl;
		ret_val = members[i].SetGolf();
		i++;
	}
	while (ret_val && i < kSize); // 在循环次数达到kSize或ret_val为0时结束循环

	if (!ret_val) { // 如果是因为用户尝试将姓名设置为空串而退出, 则i值需要修正
		i--;
	}
	std::cout << i << " member(s) processed.\n";
	for (int j = 0; j < i ; j++) {
		members[j].Show();
	}
	std::cout << "\nTHE END\n";
}