#ifndef QUATERNION_H
#define QUATERNION_H

#include<ostream> 
#include<cmath>
// BEWARE 
// constexpr I, J, K Defined in this file


class Quaternion {
    double re, i, j, k;
public:
    Quaternion() : re(0), i(0), j(0), k(0) {};
    Quaternion(double r) : re(r), i(0), j(0), k(0) {};
    Quaternion(double r, double im) : re(r), i(im), j(0), k(0) {};
    constexpr Quaternion(double a, double b, double c, double d) : 
        re(a), i(b), j(c), k(d) {};
    Quaternion(const Quaternion& q2) = default;
    Quaternion(Quaternion&& q) = default;
    Quaternion& operator= (const Quaternion& param) = default;
    Quaternion& operator= (Quaternion&& param) = default;

    friend const Quaternion conj(const Quaternion& q);
    friend double norm(const Quaternion& q);
    friend const Quaternion operator - (const Quaternion& q);
    friend const Quaternion operator - (const Quaternion& q, const double & k);
    friend const Quaternion operator - (const double& k, const Quaternion& q);
    friend const Quaternion operator -
        (const Quaternion& q1, const Quaternion& q2);
    friend const Quaternion operator + (const Quaternion& q);
    friend const Quaternion operator + (const Quaternion& q, const double& k);
    friend const Quaternion operator + (const double& k, const Quaternion& q);
    friend const Quaternion operator +
        (const Quaternion & q1, const Quaternion & q2);
    friend Quaternion operator * (const Quaternion& q1, const Quaternion& q2);

    friend std::ostream& operator << (std::ostream& os, const Quaternion& q) {
		bool first = false;
        if (q) {
            if (q.re != 0) { os << q.re; first = true; }
			if ((q.i > 0) && first) { os << "+"; }
			if (q.i != 0) { os << q.i << "i"; first = true; }
			if ((q.j > 0) && first) { os << "+"; }
			if (q.j != 0) { os << q.j << "j"; first = true; }
			if ((q.k > 0) && first) { os << "+"; }
			if (q.k != 0) { os << q.k << "k"; }
        } else { os << "0"; }
        return os;
    }

    const Quaternion& operator += (const Quaternion& param) {
        re += param.re;
        i += param.i;
        j += param.j;
        k += param.k;
        return *this;
    }

    const Quaternion& operator -= (const Quaternion& param) {
        re -= param.re;
        i -= param.i;
        j -= param.j;
        k -= param.k;
        return *this;
    }

    const Quaternion& operator *= (const Quaternion& q) {
        double new_re = re*q.R() - i*q.I() - j*q.J() - k*q.K();
        double new_i = re*q.I() + i*q.R() + j*q.K() - k*q.J();
        double new_j = re*q.J() - i*q.K() + j*q.R() + k*q.I();
        double new_k = re*q.K() + i*q.J() - j*q.I() + k*q.R();
        re = new_re;
        i = new_i;
        j = new_j;
        k = new_k;
        return *this;
    }

    inline bool operator == (const Quaternion& q) const {
        return ((re == q.re) && (i == q.i) && (j == q.j) && (k == q.k));
    }

    inline bool operator != (const Quaternion& q) const {
        return !(*this == q);
    }

    double R() const {
        return re;
    }
    double I() const {
        return i;
    }
    double J() const {
        return j;
    }
    double K() const {
        return k;
    }

    double norm() const {
        return sqrt(re*re + i*i + j*j + k*k);
    }

    const Quaternion conj() const {
        return Quaternion (re, (-1)*i, (-1)*j, (-1)*k);
    }

    explicit operator bool() const {
        return !((re == 0) && (i == 0) && (j == 0) && (k == 0));
    }
};

inline const Quaternion conj(const Quaternion& q) {
    return q.conj();
};

inline double norm(const Quaternion& q) {
    return q.norm();
};

inline const Quaternion operator - (const Quaternion& q) {
    return Quaternion((-1)*q.re, (-1)*q.i, (-1)*q.j, (-1)*q.k);
};

inline const Quaternion operator - (const Quaternion& q, const double& k) {
    return Quaternion(q.re-k, q.i, q.j, q.k);
};

inline const Quaternion operator - (const double& k, const Quaternion& q) {
    return Quaternion(k+(-q.re), -q.i, -q.j, -q.k);
};

inline const Quaternion operator - 
                                (const Quaternion& q1, const Quaternion& q2){
    return Quaternion(q1.re-q2.re, q1.i-q2.i, q1.j-q2.j, q1.k-q2.k);
};

inline const Quaternion operator + (const Quaternion& q) {
    return Quaternion(q.re, q.i, q.j, q.k);
};

inline const Quaternion operator + (const Quaternion& q, const double & k) {
    return Quaternion(q.re+k, q.i, q.j, q.k);
};

inline const Quaternion operator + (const double& k, const Quaternion& q) {
    return Quaternion(q.re+k, q.i, q.j, q.k);
};

inline const Quaternion operator + 
                        (const Quaternion& q1, const Quaternion& q2) {
    return Quaternion(q1.re+q2.re, q1.i+q2.i, q1.j+q2.j, q1.k+q2.k);
};

inline Quaternion operator * (const Quaternion& q1, const Quaternion& q2) {
    return Quaternion(
               q1.re*q2.re - q1.i*q2.i - q1.j*q2.j - q1.k*q2.k,
               q1.re*q2.i + q1.i*q2.re + q1.j*q2.k - q1.k*q2.j,
               q1.re*q2.j - q1.i*q2.k + q1.j*q2.re + q1.k*q2.i,
               q1.re*q2.k + q1.i*q2.j - q1.j*q2.i + q1.k*q2.re
           );
};

inline bool operator == (double& x, const Quaternion& q) {
    return (q == Quaternion(x));
};

constexpr Quaternion I{0, 1, 0, 0};
constexpr Quaternion J{0, 0, 1, 0};
constexpr Quaternion K{0, 0, 0, 1};

#endif
