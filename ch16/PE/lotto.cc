// 模拟彩票卡游戏

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @param n1 彩票卡上圆点的数目
 * @param n2 随机选择的圆点数目
 * @return 一个包含(按排列后的顺序)随机选择的号码的整型矢量
*/
vector<int> Lotto(int n1, int n2);

int main() {
  vector<int> winners;
  winners = Lotto(51, 6);
  cout << "Selected numbers: ";
  for (int x: winners) cout << x << " ";
  cout << endl;
}

vector<int> Lotto(int n1, int n2) {
  vector<int> dots(n1), selected(n2);
  // 创建一个包含所有可能取值的矢量: 取值范围[1, n1]
  for (int i = 0; i < n1; i++) {
    dots[i] = i + 1;
  }
  for (int i = 0; i < n2; i++) {
    // 模拟随机取数的方式: 用random_shuffle()打乱顺序, 并选择末端的元素.
    // 为避免多次取数时选到同一个值, 每一次取数之后将该数从待选数组中移除.
    random_shuffle(dots.begin(), dots.end());
    selected[i] = dots.back();
    dots.pop_back();
  }
  return selected;
}