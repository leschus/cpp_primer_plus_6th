#include <iostream>
#include "queue.h"

int main() {
  using namespace std;
  Queue<int> q(2);
  if (q.empty())
    cout << "Empty.\n";
  q.EnQueue(1);
  q.EnQueue(2);
  if (q.full())
    cout << "Full.\n";
  int item;
  q.DeQueue(item);
  cout << "Dequeue: " << item << endl;
  q.DeQueue(item);
  cout << "Dequeue: " << item << endl;
  if (q.empty())
    cout << "Empty.\n";
}

/*
测试输出:

Empty.
Full.
Dequeue: 1
Dequeue: 2
Empty.

*/