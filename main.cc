#include"counter.h"
#include<iostream>
#include<unistd.h>
#include<cmath>
using namespace std;

int main() {
  bool value[4] = {0,0,0,0};
  bool add[4] = {0,0,0,1};
  bool* p1 = value; bool* p2 = add;

  while(1) {
    p1 = bitFA(p1, p2, 4);
    printBin(p1, 4);
  }
  return 0;
}
