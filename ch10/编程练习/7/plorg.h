#include <string>

class Plorg {
 public:
  Plorg(const char *name = "Plorga");
  void update(int ci);
  void report();

 private:
  /* data */
  enum {MAX = 20, DEFAULT_CI = 50};
  char name_[MAX];
  int ci_; // 满意度
};