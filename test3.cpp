#include "quaternion.h"
Quaternion q(1., 2., 3.); // błąd kompilacji 1

int main() {
  Quaternion q1, q2, q3;
  q1.R() = 2.0;    // błąd kompilacji 2
  q1.conj() = q2;  // błąd kompilacji 3
  conj(q1) = q2;   // błąd kompilacji 4
  q1.norm() = 1.0; // błąd kompilacji 5
  norm(q1) = 1.0;  // błąd kompilacji 6
  -q1 = q2;        // błąd kompilacji 7
  (q1 + q2) = q3;  // błąd kompilacji 8
  I = q2;          // błąd kompilacji 9
  
  int a;
  a = q1;      // błąd kompilacji 10
  char b = q1; // błąd kompilacji 11
}

// QuaternionSequence qs1, qs2, qs3;
// (qs1 + qs2) = qs3; // błąd kompilacji 20
// qs1 < qs2;         // błąd kompilacji 21
// 
// QuaternionSequence qs;
// int c;
// c = qs;      // błąd kompilacji 30
// char d = qs; // błąd kompilacji 31
