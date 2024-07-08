#include <iostream>
#include "process.h"
using std::cout, std::endl;

int main()
{
  cout << "p s" << endl;
  Process pro;
  pro.planProcess();
  cout << "p e" << endl;
  return 0;
}