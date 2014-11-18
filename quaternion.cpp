#include <iostream>
#include "quaternion.h"
#include <cmath>

Quaternion::Quaternion() {
    re = i = j = k = 0;
}

Quaternion::Quaternion(double r) : re(r) {
    i = j = k = 0;
}

Quaternion::Quaternion(double r, double im) : re(r), i(im) {
    j = k = 0;
}

Quaternion::Quaternion(double a, double b, double c, double d) : 
    re(a), i(b), j(c), k(d) {};

 Quaternion::Quaternion(const Quaternion& q2) = default;
 
Quaternion::Quaternion(Quaternion&& q) = default;

Quaternion& Quaternion::operator= (const Quaternion& param) = default;

Quaternion& Quaternion::operator= (Quaternion&& param) = default;

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
	return (*this) += param;
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
	os << q.re << " + " << q.i << "i + " << q.j << "j + " << q.k <<
            "k + " << std::endl;
	return os;
}

double Quaternion::R() const {
    return re;
}

double Quaternion::I() const {
    return i;
}

double Quaternion::J() const {
    return j;
}

double Quaternion::K() const {
    return k;
}

Quaternion Quaternion::conj() {
    Quaternion result = *this;
    result.i *= -1;
    result.j *= -1;
    result.k *= -1;
    return result;
}

Quaternion conj(const Quaternion& q) {
    Quaternion tmp = q;
    return tmp.conj();
}

double Quaternion::norm() const {
    return sqrt(re*re + i*i + j*j + k*k);
}

double norm(const Quaternion& q) {
    return q.norm();
}

