// 对于经常要对容器进行增删操作的场景, 常使用list容器而非vector. 现假设已经使用了list容器
// 存储了大量整数, 并要对容器中的整数进行排序, 有两种方案可供选择:
//    1. 使用list的sort()方法进行就地排序;
//    2. 将list元素拷贝到一个vector中, 再使用STL中的sort()函数对该vector进行排序, 最后
//    将排序后的vector中元素拷贝回原list.
//
// 虽然说对vector进行排序速度更快, 但方案2因为多了两次拷贝操作, 所以其总共耗时并非一定比方
// 案1少. 本文件通过编写程序比较这两种方案的耗时. 为使差异足够明显, 待排序数组的元素数量要
// 够大, 如100000, 1000000或10000000.

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int kNumSize = 10000000;

int main() {
  // 创建大型vector<int>对象vi0, 并使用rand()给它提供初始值
  srand(time(0));
  vector<int> vi0(kNumSize);
  for (int i = 0; i < kNumSize; i++)
    vi0[i] = rand();
  // 创建vector<int>对象vi和list<int>对象li, 它们的长度和初始值都和vi0相同
  vector<int> vi(vi0);
  list<int> li(vi0.begin(), vi0.end());

  clock_t start, end;
  // 使用STL算法函数sort()对vi进行排序, 并计算时间
  start = clock();
  sort(vi.begin(), vi.end());
  end = clock();
  cout << "time cost of sorting vi: "
       << (double)(end - start) / CLOCKS_PER_SEC << endl;
  // 使用list的sort()方法对li进行排序, 并计算时间
  start = clock();
  li.sort();
  end = clock();
  cout << "time cost of sorting li: "
       << (double)(end - start) / CLOCKS_PER_SEC << endl;

  copy(vi0.begin(), vi0.end(), li.begin()); // 将li恢复到未排序状态

  // 模拟方案2: 先将li元素拷贝到vi, 再对vi进行排序, 再将vi元素拷贝回li
  // 计算这个过程的总耗时.
  start = clock();
  copy(li.begin(), li.end(), vi.begin());
  sort(vi.begin(), vi.end());
  copy(vi.begin(), vi.end(), li.begin());
  end = clock();
  cout << "total time cost of plan 2: "
       << (double)(end - start) / CLOCKS_PER_SEC << endl;

  cout << "Done.\n";
}

/*
当待排序数组的规模为10000000时, 测试结果如下:

time cost of sorting vi: 2.534
time cost of sorting li: 14.819
total time cost of plan 2: 6.262

可见, 方案2虽然多执行了两遍拷贝, 但其执行耗时仍然比方案1少很多.
*/