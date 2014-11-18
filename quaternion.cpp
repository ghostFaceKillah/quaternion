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

Quaternion operator+(double x, const Quaternion& q) {
	Quaternion tmp(x + q.re, q.i, q.j, q.k);
	return tmp;
}

/*Quaternion operator+(const Quaternion& q, double x) {
	Quaternion tmp(x + q.re, q.i, q.j, q.k);
	return tmp;
}*/

Quaternion Quaternion::operator- () {
	Quaternion result = *this;
	result.re *= -1;
	result.i *= -1;
	result.j *= -1;
	result.k *= -1;
	return result;
}

Quaternion operator-(double x, const Quaternion& q) {
	Quaternion tmp(x - q.re, q.i, q.j, q.k);
	return tmp;
}

/*Quaternion operator-(const Quaternion& q, double x) {
	Quaternion tmp(x - q.re, q.i, q.j, q.k);
	return tmp;
}*/

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

/*Quaternion operator*=(const Quaternion& q1, const Quaternion& q2) {
	double re = q1.re * q2.re - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
	double i = q1.re * q2.i + q1.i * q2.re + q1.j * q2.k - q1.k * q2.j;
	double j = q1.re * q2.j - q1.i * q2.k + q1.j * q2.re + q1.k * q2.i;
	double k = q1.re * q2.k + q1.i * q2.j - q1.j * q2.i + q1.k * q2.re;
	Quaternion tmp(re, i, j, k);
	return tmp;
}*/

Quaternion Quaternion::operator+ (const Quaternion& param) {
	return (*this) += param;
}

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

bool Quaternion::operator!=(const Quaternion& q) const {
	return !(*this == q);
}

Quaternion::operator bool() const {
	return !((re == 0) && (i == 0) && (j == 0) && (k == 0));
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
	if (!q) {
		os << q.re;
		if (q.i > 0) { os << "+"; }
		if (q.i != 0) { os << q.i << "i"; }
		if (q.j > 0) { os << "+"; }
		if (q.j != 0) { os << q.j << "j"; }
		if (q.k > 0) { os << "+"; }
		if (q.k != 0) { os << q.k << "k"; }
	} else { os << "0" << std::endl; }
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

Quaternion const I = Quaternion(0., 1., 0., 0.);
Quaternion const J = Quaternion(0., 0., 1., 0.);
Quaternion const K = Quaternion(0., 0., 0., 1.);
/* Z constami potrzeba głębszej rokminy, bo trzeba ogarnąć czy 
 * inaczej napisać operatory, czy jakieś specjalne dla tych stałych 
 * stworzyć, bo zapis I * I (i inne działania) powinien chyba zwracać 
 * nowy Quaternion 
 */
