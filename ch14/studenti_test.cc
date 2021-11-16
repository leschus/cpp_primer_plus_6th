// 除了包含头文件studenti.h而非student.h外,
// 本文件和student_test.cc内容完全相同

#include <iostream>
#include "studenti.h"
using namespace std;

void set(Student &stu, int n);
const int pupils = 3;
const int quizzes = 5;

int main() {
  Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
  int i;
  for (i = 0; i < pupils; i++) {
    set(ada[i], quizzes);
  }
  cout << "\nStudent List:\n";
  for (i = 0; i < pupils; i++) {
    cout << ada[i].Name() << endl;
  }
  cout << "\nResults:";
  for (i = 0; i < pupils; i++) {
    cout << endl << ada[i];
    cout << "Avarage: " << ada[i].Average() << endl;
  }
  cout << "Done!\n";
}

void set(Student &stu, int n) {
  cout << "Please enter the student's name: ";
  getline(cin, stu);
  cout << "Please enter " << n << " quiz scores:\n";
  for (int i = 0; i < n; i++) {
    cin >> stu[i];
  }
  while (cin.get() != '\n')
    continue;
}

/*
测试输出:

Please enter the student's name: Gil Bayts
Please enter 5 quiz scores:
92 94 96 93 95
Please enter the student's name: Pat Roone
Please enter 5 quiz scores:
83 89 72 78 95
Please enter the student's name: Fleur O'Day
Please enter 5 quiz scores:
92 89 96 74 64

Student List:
Gil Bayts
Pat Roone
Fleur O'Day

Results:
Scores for Gil Bayts:
92 94 96 93 95
Avarage: 94

Scores for Pat Roone:
83 89 72 78 95
Avarage: 83.4

Scores for Fleur O'Day:
92 89 96 74 64
Avarage: 83
Done!

*/