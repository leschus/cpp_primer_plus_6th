#ifndef VINTAGE_PORT_H_
#define VINTAGE_PORT_H_

#include <iostream>
#include "port.h"

class VintagePort : public Port {
 public:
  VintagePort();
  VintagePort(const char *brand, int bottles, const char * nickname, int year);
  VintagePort(const VintagePort &vp);
  ~VintagePort() { delete [] nickname_; }
  VintagePort & operator=(const VintagePort &vp);
  void Show() const;
  friend std::ostream & operator<<(std::ostream &os, const VintagePort &vp);

 private:
  /* data */
  char *nickname_;
  int year_;
};

#endif // VINTAGE_PORT_H_