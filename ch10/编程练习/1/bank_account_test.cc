// BankAccountTest.cc

#include <iostream>
#include <string>
#include "bank_account.h"

int main() {
  BankAccount leo; // 使用默认(无参)构造方式
  leo.Show();
  BankAccount lancy("Lancy", "123abc@xyz.com", 8241.32); // 使用含参构造方式
  lancy.Show();
  lancy.Deposit(-200); // 试图存入一个非法金额
  lancy.Show();
  lancy.Deposit(200);
  lancy.Show();
  lancy.Withdraw(-200); // 试图取出一个非法金额
  lancy.Show();
  lancy.Withdraw(10000); // 试图取出一个非法金额(超出已有存款值)
  lancy.Show();
  lancy.Withdraw(200);
  lancy.Show();
}