#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
 public:
  Customer();
  void set(long arrive_time);
  long when() const { return arrive_time_; }
  int ptime() const { return process_time_; }

 private:
  /* data */
  long arrive_time_;
  int process_time_;
};

#endif // CUSTOMER_H_