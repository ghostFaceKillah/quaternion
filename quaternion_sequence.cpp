#include <iostream>
#include <map>
#include <vector>
#include "quaternion_sequence.h"

QuaternionSequence::QuaternionSequence() {
    n++;
}

QuaternionSequence::QuaternionSequence(std::map<QuaternionSequence::size_type, Quaternion>&& q_map){
    n++;
    data = std::move(std::map<QuaternionSequence::size_type, Quaternion> map);
}

QuaternionSequence::QuaternionSequence(std::map<QuaternionSequence::size_type, Quaternion>& q_map){
    n++;
    data = std::map<QuaternionSequence::size_type, Quaternion> map;
}

QuaternionSequence::QuaternionSequence(std::vector<Quaternion>& v){
    n++;
    for (int i = 0; i < q_vector.size(); ++i) {
        if ((Quaternion) v[i])
            data[i] = v[i];
    }
}

QuaternionSequence::QuaternionSequence(const QuaternionSequence& qs) {
    n++;
    data = std::map<QuaternionSequence::size_type, Quaternion> map(qs.data);
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

QuaternionSequence QuaternionSequence::operator + (const QuaternionSequence& qs) {
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

QuaternionSequence QuaternionSequence::operator - (const QuaternionSequence& qs) {
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

QuaternionSequence operator * (const QuaternionSequence& qs) {
    return QuaternionSequence(*this) *= qs;
}

//tutej skończyłem !!!! ważne 
QuaternionSequence operator * (const Quaternion& q, const QuaternionSequence& qs) {
    for (auto i : qs.data) {
        data[i.first] *= i.second;
        if (!data[i.first])
            data.erase(i.first);
    }
    return *this;
    return QuaternionSequence(*this) *= qs;
}

QuaternionSequence operator * (const Quaternion& q, const QuaternionSequence& qs) {
    return QuaternionSequence(*this) *= qs;
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

void insert(const size_type& n, const Quaternion& q){
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
    for (auto i : qs.data) {
        if (i != qs.data.begin())
            os << ", ";
        os << i.first << " -> " << i.second;
    }
    os << ")";
    return os;
}

int count(){
    return n;
}
