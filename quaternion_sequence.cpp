#include <iostream>
#include <map>
#include <vector>
#include "quaternion_sequence.h"
int QuaternionSequence::n = 0;

QuaternionSequence::QuaternionSequence() {
    n++;
}

QuaternionSequence::~QuaternionSequence() {
    n--;
}

QuaternionSequence::QuaternionSequence(const std::map<QuaternionSequence::size_type,
        Quaternion>&& q_map){
    n++;
    data = std::move(q_map);
}

QuaternionSequence::QuaternionSequence(const std::map<QuaternionSequence::size_type,
        Quaternion>& map){
    n++;
    data = std::map<QuaternionSequence::size_type, Quaternion>(map);
}

QuaternionSequence::QuaternionSequence(const std::vector<Quaternion>& v){
    n++;
    for (int i = 0; i < v.size(); ++i) {
        if ((Quaternion) v[i])
            data[i] = v[i];
    }
}

QuaternionSequence::QuaternionSequence(const QuaternionSequence& qs) {
    n++;
    data = std::map<QuaternionSequence::size_type, Quaternion>(qs.data);
}

QuaternionSequence::QuaternionSequence(QuaternionSequence&& qs) = default;

QuaternionSequence& QuaternionSequence::operator = (const QuaternionSequence& qs) {
    data = qs.data;
    return *this;
}
QuaternionSequence& QuaternionSequence::operator = (QuaternionSequence&& qs) = default;

QuaternionSequence& QuaternionSequence::operator +=(const QuaternionSequence& qs) {
    for (auto i : qs.data) {
        data[i.first] += i.second;
        if (!data[i.first])
            data.erase(i.first);
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator + 
                                          (const QuaternionSequence& qs) const {
    return QuaternionSequence(*this) += qs;
}

QuaternionSequence& QuaternionSequence::operator -= (const QuaternionSequence& qs) {
    for (auto i : qs.data) {
        data[i.first] -= i.second;
        if (!data[i.first])
            data.erase(i.first);
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator - (
                                            const QuaternionSequence& qs) const{
    return QuaternionSequence(*this) -= qs;
}

QuaternionSequence& QuaternionSequence::operator *= (const QuaternionSequence& qs) {
    for (auto i : qs.data) {
        data[i.first] *= i.second;
        if (!data[i.first])
            data.erase(i.first);
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator * (const QuaternionSequence& qs) {
    return QuaternionSequence(*this) *= qs;
}

const QuaternionSequence operator * (const Quaternion& q, const QuaternionSequence& qs) {
    QuaternionSequence resu(qs);
    for (auto i : resu.data) {
        resu.data[i.first] = q * resu.data[i.first];
        if (!resu.data[i.first])
            resu.data.erase(i.first);
    }
    return resu;
}

const QuaternionSequence operator * (const QuaternionSequence& qs, const Quaternion& q ) {
    QuaternionSequence resu(qs);
    for (auto i : resu.data) {
        resu.data[i.first] = resu.data[i.first] * q;
        if (!resu.data[i.first])
            resu.data.erase(i.first);
    }
    return resu;
}


const QuaternionSequence operator * (const QuaternionSequence &qs, double q) {
    std::cout << "getting called hehehehe" << std::endl;

    Quaternion d(q);
    std::cout << "argument is " << d << std::endl;
    QuaternionSequence resu(qs);
    for (auto i : resu.data) {
        resu.data[i.first] = resu.data[i.first] * d;
        std::cout << "wynik kurwa  is " << resu.data[i.first] << std::endl;
        if (!resu.data[i.first])
            resu.data.erase(i.first);
    }
    return resu;

}
const QuaternionSequence operator * (double q, const QuaternionSequence &qs) {
    Quaternion d(q);
    QuaternionSequence resu(qs);
    for (auto i : resu.data) {
        resu.data[i.first] = d * resu.data[i.first];
        if (!resu.data[i.first])
            resu.data.erase(i.first);
    }
    return resu;
}

const Quaternion QuaternionSequence::operator[](const size_type i) const {
    auto iter = data.find(i);
    if (iter == data.end()) {
        return Quaternion();
    }
    else {
        return iter->second;
    }
}

void QuaternionSequence::insert(const size_type n, const Quaternion &q) {
    if (q)
        data[n] = q;
    else
        data.erase(n);
}

bool QuaternionSequence::operator == (const QuaternionSequence& qs) const {
    auto iter = qs.data.begin();
    for (auto quaternion : data)
    {
        if (*iter != quaternion)
            return false;
        iter++;
    }
    return true;
}

bool QuaternionSequence::operator != (const QuaternionSequence& qs) const {
    return !((*this) == qs);
}

QuaternionSequence::operator bool() const {
    return n > 0;
}

std::ostream& operator << (std::ostream& os, const QuaternionSequence& qs) {
    os << std::string("(");
    for (auto i = qs.data.begin(); i != qs.data.end(); ++i) {
        if (i != qs.data.begin())
            os << ", ";
        os << i->first << " -> " << i->second;
    }
    os << ")";
    return os;
}

int QuaternionSequence::count() {
    return n;
}
