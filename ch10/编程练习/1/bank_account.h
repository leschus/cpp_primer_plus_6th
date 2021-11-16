// 定义BankAccount类
// 提供存款/取款/查询功能

#include <string>

class BankAccount {
 public:
  // 构造函数, 各参数均提供了默认值
  BankAccount(const std::string name = "Unknown",
      const std::string account = "Unknown", double balance = 0);
  // 显示储户姓名, 账号, 存款
  void Show();
  // 存款, 当金额不合法时, 返回false
  bool Deposit(double d);
  // 取款, 当金额不合法时, 返回false
  bool Withdraw(double d);

 private:
  std::string name_;     // 储户姓名
  std::string account_;  // 账号
  double balance_;        // 存款
};