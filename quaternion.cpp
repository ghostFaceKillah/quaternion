#include <iostream>
#include "quaternion.h"

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


Quaternion& Quaternion::operator= (const Quaternion& param) {
	if (this != &param) {
		re = param.re;
		i = param.i;
		j = param.j;
		k = param.k;
	}
	return *this;
}

Quaternion Quaternion::operator+ () {
	Quaternion result = *this;
	return result;
}

Quaternion Quaternion::operator- () {
	Quaternion result = *this;
	result.re *= -1;
	result.i *= -1;
	result.j *= -1;
	result.k *= -1;
	return result;
}

Quaternion& Quaternion::operator+=(const Quaternion& param) {
	re += param.re;
	i += param.i;
	j += param.j;
	k += param.k;
	return *this;
}
Quaternion& Quaternion::operator-=(const Quaternion& param) {
	re -= param.re;
	i -= param.i;
	j -= param.j;
	k -= param.k;
	return *this;
}
Quaternion& Quaternion::operator*=(const Quaternion& param) {
	re = re * param.re - i * param.i - j * param.j - k * param.k;
	i = re * param.i + i * re + j * param.k - k * param.j;
	j = re * param.j - i * param.k + j * param.re + k * param.i;
	k = re * param.k + i * param.j - j * param.i + k * param.re;
	return *this;
}
Quaternion Quaternion::operator+ (const Quaternion& param) {
	Quaternion result = *this;
	result += param;
	return result;
}
/*
const MyClass MyClass::operator+(const MyClass &other) const {
	MyClass result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
	result += other;            // Use += to add other to the copy.
	return result;              // All done!
}
const MyClass MyClass::operator+(const MyClass &other) const {
	return MyClass(*this) += other;
}
*/

Quaternion Quaternion::operator- (const Quaternion& param) {
	Quaternion result = *this;
	result -= param;
	return result;
}
Quaternion Quaternion::operator* (const Quaternion& param) {
	Quaternion result = *this;
	result *= param;
	return result;
}
/*
MyClass& MyClass::operator=(const MyClass &rhs) {
	// 1.  Deallocate any memory that MyClass is using internally
	// 2.  Allocate some memory to hold the contents of rhs
	// 3.  Copy the values from rhs into this instance
	// 4.  Return *this
} 
  MyClass& MyClass::operator=(const MyClass &rhs) {
	  // Check for self-assignment!
	  if (this == &rhs)      // Same object?
		return *this;        // Yes, so skip assignment, and just return *this.
	  // ... // Deallocate, allocate new space, copy values...
	  return *this;
}
	  
*/

bool Quaternion::operator==(const Quaternion& q) const {
	return ((re == q.re) && (i == q.i) && (j == q.j) && (k == q.k));
}
/*
bool MyClass::operator==(const MyClass &other) const;
*/
bool Quaternion::operator!=(const Quaternion& q) const {
	return !(*this == q);
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
	os << q.re << " + " << q.i << "i + " << q.j << "j + " << q.k << "k + " << std::endl;
	return os;
}

