#include"counter.h"
#include<iostream>
#include<unistd.h>
#include<cmath>
using namespace std;


bool* halfAdd(bool p1, bool p2) {
  bool* r = new bool[2];
  *r = (p1)^(p2);
  *(r+1) = (p1)&&(p2);
  return r;
}

bool* fullAdd(bool p1, bool p2, bool ci) {
  bool* tempSum = halfAdd(p1, p2);
  bool* sum = halfAdd(*tempSum, ci);
  bool* r = new bool[2];
  *r = *sum;
  *(r+1) = *(tempSum+1) || *(sum+1);
  return r;
}

bool* bitFA(bool* p1, bool* p2, int length) {
  bool* sum = new bool[length];
  bool* tempSum = new bool[2];

  tempSum = halfAdd(*(p1+7), *(p2+7));
  *(sum+7) = *tempSum;

  for(int i=length-2; i>=0; i--) {
    tempSum = fullAdd(*(p1+i), *(p2+i), *(tempSum+1));
    *(sum+i) = *tempSum;
  }


  return sum;
}

int binToDec(bool* p, int length) {
  int value = 0;
  for(int i=0; i<length; i++) {
    value += (*(p+i)) * (pow(2, (length-1-i)));
  }
  return value;
}

void printBin(bool* p, int length) {
  for(int i=0; i<length; i++) {
    cout<<*(p+i);
  }
  cout<<endl;
}
