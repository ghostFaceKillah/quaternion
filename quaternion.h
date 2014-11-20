#include<ostream> 
#include<cmath>

class Quaternion {
    double re, i, j, k;
public:
    // constructors
    Quaternion() {
        re = i = j = k = 0;
    }

    Quaternion(double r) : re(r) {
        i = j = k = 0;
    }

    Quaternion(double r, double im) : re(r), i(im) {
        j = k = 0;
    }

    constexpr Quaternion(double a, double b, double c, double d) : 
        re(a), i(b), j(c), k(d) {};

    Quaternion(const Quaternion& q2) = default;

    Quaternion(Quaternion&& q) = default;

    Quaternion& operator= (const Quaternion& param) = default;

    Quaternion& operator= (Quaternion&& param) = default;

    Quaternion operator+ () const {
        Quaternion result = *this;
        return result;
    }

    Quaternion operator- () const {
        Quaternion result = *this;
        result.re *= -1;
        result.i *= -1;
        result.j *= -1;
        result.k *= -1;
        return result;
    }

    Quaternion operator+ (const Quaternion& param) const {
        Quaternion result = *this;
        result += param;
        return result;
    }

    Quaternion operator- (const Quaternion& param) const {
        Quaternion result = *this;
        result -= param;
        return result;
    }

    Quaternion operator* (const Quaternion& param) const {
        Quaternion result = *this;
        result *= param;
        return result;
    }

    const Quaternion& operator+=(const Quaternion& param) {
        re += param.re;
        i += param.i;
        j += param.j;
        k += param.k;
        return *this;
    }

    const Quaternion& operator-=(const Quaternion& param) {
        re -= param.re;
        i -= param.i;
        j -= param.j;
        k -= param.k;
        return *this;
    }

    const Quaternion& operator*=(const Quaternion& q) {

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

    // Quaternion & operator*=(const Quaternion & q) {
    //     Quaternion qs = (*this) * q;
    //     re =qs.R();
    //         i = qs.I();
    //         j = qs.J();
    //         k = qs.K();

    //     return (*this);
    // }

    bool operator==(const Quaternion& q) const {
        return ((re == q.re) && (i == q.i) && (j == q.j) && (k == q.k));
    }

    bool operator!=(const Quaternion& q) const {
        return !(*this == q);
    }

    // getters
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

    inline const Quaternion conj() const {
        return Quaternion (re, (-1)*i, (-1)*j, (-1)*k);
    }

    friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);

    explicit operator bool() const {
        return !((re == 0) && (i == 0) && (j == 0) && (k == 0));
    }
};

double norm(const Quaternion& q);
Quaternion conj(const Quaternion& q);

double norm(const Quaternion& q) {
    return q.norm();
}

Quaternion conj(const Quaternion& q) {
    Quaternion tmp = q;
    return tmp.conj();
}

// operators
Quaternion operator-(double x, const Quaternion& q) {
    return Quaternion(x -q.R(), (-1)*q.I(), (-1)*q.J(), (-1)*q.K());
}

Quaternion operator-(const Quaternion& q, double x) {
    return Quaternion(q.R() - x, q.I(), q.J(), q.K());
}

Quaternion operator+(double x, const Quaternion& q) {
    return Quaternion(q.R() + x, q.I(), q.J(), q.K());
}

bool operator==(double x, const Quaternion& q) {
    return (q == Quaternion (x));
}


std::ostream& operator<<(std::ostream& os, const Quaternion& q) {
    if (q) {
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


constexpr Quaternion I{0, 1, 0, 0};
constexpr Quaternion J{0, 0, 1, 0};
constexpr Quaternion K{0, 0, 0, 1};

