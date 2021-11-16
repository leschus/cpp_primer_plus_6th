#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include "customer.h"

using namespace std;
using QUEUE::Queue;

const int MINS_PER_HOUR = 60;

bool newcustomer(double x); // is there a new customer?

int main() {
  std::srand(time(0));      // random initializing of rand()

  cout << "Case Study: Bank of Heather Automatic Teller\n";
  cout << "Enter maximum size of queue: ";
  int size;
  cin >> size;
  Queue line(size);         // line queue holds up to size people

  cout << "Enter the number of simulation hours: ";
  int hours;
  cin >> hours;
  // simulation will run 1 cycle per mimute
  long cyclelimit = MINS_PER_HOUR * hours;

  cout << "Enter the average number of customers per hour: ";
  double perhour;           // average # of arrival per hour
  cin >> perhour;
  double min_per_cust;      // average time between arrivals
  min_per_cust = MINS_PER_HOUR / perhour;

  Customer temp;
  long turnaways = 0;   // turned away by full queue
  long customers = 0;   // joined the queue
  long served = 0;      // served during the simulation
  long sum_line = 0;    // cumulative line length
  int wait_time;        // time until autoteller is free
  long line_wait = 0;   // cumulative time in line

  // running the simulation
  for (int cycle = 0; cycle < cyclelimit; cycle++) {
    if(newcustomer(min_per_cust)) { // have newcomer
      if (line.full())
        turnaways++;
      else {
        customers++;
        temp.set(cycle);    // cycle = time of arrival
        line.enqueue(temp); // add newcomer to line
      }
    }
    if (wait_time <= 0 && !line.empty()) {
      line.dequeue(temp);   // attend next customer
      wait_time = temp.ptime();
      line_wait += cycle - temp.when();
      served++;
    }
    if (wait_time > 0)
      wait_time--;
    sum_line += line.count();
  }

  // reporting results
  if (customers > 0) {
    cout << "customers accepted: " << customers << endl;
    cout << "  customers served: " << served << endl;
    cout << "         turnaways: " << turnaways << endl;
    cout << "average queue size: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double) sum_line / cyclelimit << endl;
    cout << " average wait time: "
         << (double) line_wait / served << " minutes\n";
  }
  else
    cout << "No customers!\n";
  cout << "Done!\n";
}

bool newcustomer(double x) {
  return (rand() * x / RAND_MAX < 1);
}