// BankAccount.cc
#include <iostream>
#include "bank_account.h"

// 注意: 形参的默认值只需要在函数原型中给出
BankAccount::BankAccount(std::string name, std::string account, double balance) {
  name_ = name;
  account_ = account;
  balance_ = balance;
}

void BankAccount::Show() {
  using std::cout;
  using std::endl;
  using std::ios_base;
  // 设置浮点数的输出格式: 使用定点小数, 保留小数点后两位
  ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = cout.precision(2);
  cout << "Name: " << name_
    << "\nAccount: " << account_ << "\nBalance: " << balance_ << endl;
  // 复原浮点数的输出格式
  cout.setf(orig, ios_base::floatfield);
  cout.precision(prec);
}

bool BankAccount::Deposit(double d) {
  using std::cout;
  if(d <= 0) {
    cout << "Invalid number.\nProcess aborted.\n";
    return false;
  }
  balance_ += d;
  return true;
}

bool BankAccount::Withdraw(double d) {
  using std::cout;
  if(d <= 0) {
    cout << "Invalid number.\nProcess aborted.\n";
    return false;
  }
  else if(d > balance_) {
    cout << "You don't have that much money.\nProcess aborted.\n";
    return false;
  }
  balance_ -= d;
  return true;
}