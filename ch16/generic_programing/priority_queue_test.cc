// priority_queue, 是对queue概念的改进.
//
//  它支持与queue相同的基本操作. 两者的主要区别在于: priority_queue中最大的元素总会被
// 移至队首; 并且, priority_queue默认基于vector实现, 而queue默认基于deque实现.
//
//  priority_queue提供一个可选的构造函数参数, 该参数提供进行元素优先级比较的函数对象,
// 默认值为less<value_type>


#include <queue>  // 要使用priority_queue, 需包含<queue>头文件
#include <string>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::string;
using std::priority_queue;
using std::greater;
using std::cout;
using std::endl;
using std::vector;

// 一个简单的模拟进程类, 包含执行优先级
class Process {
 public:
  enum { kDefaultPriority = SCHAR_MAX };
  Process(int id, int n = kDefaultPriority)
      : pid_(id), priority_(n) {
    cout << "new process: " << pid_ << ", " << priority_ << endl;
  }
  ~Process() {}
  bool operator>(const Process &p) const { return priority_ > p.priority_; }
  int pid() const { return pid_; }
  int priority() const { return priority_; }
 private:
  int pid_;          // 进程id
  int priority_;      // 进程优先级, 值越小优先级越高(0优先级最高)
};

void log(const char *msg) {
  cout << msg << endl;
}

void log1(const char *msg, int val) {
  cout << msg << ": " << val << endl;
}

void log2(const char *msg, const Process &proc) {
  cout << msg << ": " << proc.pid() << ", " << proc.priority() << endl;
}

int main() {
  // 创建一个进程管理器(优先队列), 使用greater而非默认的less, 从而使得队列总将
  // 值最小的元素放至队首.
  priority_queue<Process, vector<Process>, greater<Process> > process_manager;
  // 下述声明方式有误: 编译器将其视为函数声明...(课本示例是这么写的, 应该是有误)
  // priority_queue<Process> process_manager(greater<Process>);
  srand(time(0));
  /* 随机模拟进程入队的场景
      1. 随机生成一个整数process_num, 表示接下来将入队的进程数量. 取值范围: [5, 10]
      2. 循环process_num次, 每次随机生成一个[0, SCHAR_MAX]内的整数表示新进程优先级,
      以及一个[0, RAND_MAX]的整数表示新进程PID, 并将新进程加入队列
   */
  int process_num = rand() % 6 + 5;
  log1("number of comming processes", process_num);
  while (process_num--) {
    int priority = rand() % (SCHAR_MAX + 1);
    int pid = rand();
    process_manager.push(Process(pid, priority));
  }
  log1("priority_queue size", process_manager.size());
  while (!process_manager.empty()) {
    log2("current top process", process_manager.top());
    log("poping out...");
    process_manager.pop();
  }
  log("All processes poped.");
  log("Done!");
}