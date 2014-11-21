#ifndef QUATERNION_SEQUENCE_H
#define QUATERNION_SEQUENCE_H

#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include "quaternion.h"

class QuaternionSequence {
public:
    typedef unsigned int size_type;
private:
    std::map<size_type, Quaternion> quaternions;
    static int how_many;
public:

    QuaternionSequence ();

    ~QuaternionSequence();

    QuaternionSequence (const std::map<QuaternionSequence::size_type, Quaternion> &map);

    QuaternionSequence(const std::vector<Quaternion> &v);

    QuaternionSequence (const QuaternionSequence &qs);
        QuaternionSequence (QuaternionSequence&& qs);

    QuaternionSequence& operator=(const QuaternionSequence &qs1);
        QuaternionSequence& operator=(QuaternionSequence &&qs);

    QuaternionSequence& operator+=(const QuaternionSequence &qs);

    const QuaternionSequence operator+(const QuaternionSequence &qs) const;

    QuaternionSequence& operator-=(const QuaternionSequence &qs);

    const QuaternionSequence operator-(const QuaternionSequence &qs) const;

    QuaternionSequence& operator*=(const Quaternion &q);

    const QuaternionSequence operator*(const Quaternion &q) const;

    QuaternionSequence& operator*=(const QuaternionSequence &qs);

    const QuaternionSequence operator*(const QuaternionSequence &qs);

    const Quaternion operator[](const size_type i) const;

    void insert(const size_type n, const Quaternion &q);

    bool operator==(QuaternionSequence const &other) const;

    bool operator!=(QuaternionSequence const &other) const;

    explicit operator bool() const;

    static int count();

    friend std::ostream& operator<<(std::ostream& out, const QuaternionSequence &qs);

};

const QuaternionSequence operator*(const Quaternion& q, const QuaternionSequence& qs);

#endif