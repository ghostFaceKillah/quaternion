#include<iostream>
#include<quaternion.h>

Quaternion::Quaternion() {
    re = i = j = k = 0;
}

Quaternion::Quaternion(float r) : re(r) {
    i = j = k = 0;
}

Quaternion::Quaternion(float r, float im) : re(r), i(im) {
    j = k = 0;
}

Quaternion::Quaternion(float a, float b, float c, float d) : 
    re(a), i(b), j(c), k(d) {};

Quaternion::Quaternion(const Quaternion& q2) :
    re(q2.re), i(q2.i), j(q2.j), k(q2.k) {};


