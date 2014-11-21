#ifndef QUATERNION_SEQUENCE_H
#define QUATERNION_SEQUENCE_H

#include <ostream>
#include <map>
#include <vector>
#include "quaternion.h"

class QuaternionSequence {
public:
    typedef unsigned int size_type;

    QuaternionSequence();
    ~QuaternionSequence();
    QuaternionSequence (
            const std::map<QuaternionSequence::size_type, Quaternion> &map);
    QuaternionSequence (
            const std::map<QuaternionSequence::size_type, Quaternion> &&map);

    QuaternionSequence(const std::vector<Quaternion> &v);
    QuaternionSequence (const QuaternionSequence &qs);
    QuaternionSequence (QuaternionSequence&& qs);

    QuaternionSequence& operator += (const QuaternionSequence &qs);
    const QuaternionSequence operator + (const QuaternionSequence &qs) const;
    QuaternionSequence& operator -= (const QuaternionSequence &qs);
    const QuaternionSequence operator - (const QuaternionSequence &qs) const;
    QuaternionSequence& operator *= (const Quaternion &q);
    const QuaternionSequence operator * (const Quaternion &q) const;
    QuaternionSequence& operator *= (const QuaternionSequence &qs);
    const QuaternionSequence operator * (const QuaternionSequence &qs);

    const Quaternion operator [] (const size_type i) const;
    void insert(const size_type n, const Quaternion &q);
    QuaternionSequence& operator = (const QuaternionSequence &qs);
    QuaternionSequence& operator = (QuaternionSequence &&qs);
    bool operator == (QuaternionSequence const &other) const;
    bool operator != (QuaternionSequence const &other) const;
    explicit operator bool() const;
    static int count();
    friend std::ostream& operator << (
            std::ostream& out, const QuaternionSequence &qs);
    friend const QuaternionSequence operator * (const QuaternionSequence &qs, const Quaternion &q);
    friend const QuaternionSequence operator * (const Quaternion &q, const QuaternionSequence &qs);
    friend const QuaternionSequence operator * (const QuaternionSequence &qs, double q);
    friend const QuaternionSequence operator * (double q, const QuaternionSequence &qs);
private:
    std::map<size_type, Quaternion> data;
    static int n;
};


#endif
