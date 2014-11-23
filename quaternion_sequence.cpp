#include <iostream>
#include <map>
#include <vector>
#include "quaternion_sequence.h"

int QuaternionSequence::qs_number = 0;

QuaternionSequence::QuaternionSequence() {
    qs_number++;
}

QuaternionSequence::~QuaternionSequence() {
    qs_number--;
}

QuaternionSequence::QuaternionSequence(const std::map<QuaternionSequence::size_type,
                                       Quaternion>&& q_map) {
    qs_number++;
    data = std::move(q_map);
}

QuaternionSequence::QuaternionSequence(const std::map<QuaternionSequence::size_type,
                                       Quaternion>& map){
    qs_number++;
    data = std::map<QuaternionSequence::size_type, Quaternion>(map);
}

QuaternionSequence::QuaternionSequence(const std::vector<Quaternion>& v) {
    qs_number++;
    for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
        if (v[i]) // hmm dlaczego tu było rzutowanie na quaternion?
            data[i] = v[i];
    }
}

QuaternionSequence::QuaternionSequence(const QuaternionSequence& qs) {
    qs_number++;
    data = std::map<QuaternionSequence::size_type, Quaternion>(qs.data);
}

QuaternionSequence::QuaternionSequence(QuaternionSequence&& qs) {
    data = std::move(qs.data);
    qs_number++;
}

QuaternionSequence& QuaternionSequence::operator = (const QuaternionSequence& qs) =default;

QuaternionSequence& QuaternionSequence::operator = (QuaternionSequence&& qs) = default;

QuaternionSequence& QuaternionSequence::operator +=(const QuaternionSequence& qs) {
    /* iterating and erasing on different maps */
    for (const auto &i : qs.data) {
        data[i.first] += i.second;
        /* if data[i.first] is 0-quaternion, it should be removed */
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
    /* iterating and erasing on different maps */
    for (const auto &i : qs.data) {
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
    QuaternionSequence tmp(qs);
    /* iterating and erasing on the same map */
    for (auto it = data.begin(); it != data.end();) {
        it->second *= tmp.data[it->first];
        /* every line is important! */
        if (!it->second)
            data.erase(it++);
        else
            ++it;
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator * (const QuaternionSequence& qs) {
    return QuaternionSequence(*this) *= qs;
}

const QuaternionSequence operator * (const Quaternion& q, const QuaternionSequence& qs) {
    QuaternionSequence res(qs);
    for (auto it = res.data.begin(); it != res.data.end();) {
        it->second = q * it->second;
        if (!it->second)
            res.data.erase(it++);
        else
            ++it;
    }
    return res;
}

const QuaternionSequence operator * (const QuaternionSequence& qs, const Quaternion& q ) {
    QuaternionSequence res(qs);
    for (auto it = res.data.begin(); it != res.data.end();) {
        it->second *= q;
        if (!it->second)
            res.data.erase(it++);
        else
            ++it;
    }
    return res;
}


const QuaternionSequence operator * (const QuaternionSequence &qs, double d) {
    Quaternion q(d);
    QuaternionSequence res(qs);
    for (auto it = res.data.begin(); it != res.data.end();) {
        it->second *= q;
        if (!it->second)
            res.data.erase(it++);
        else
            ++it;
    }
    return res;

}
const QuaternionSequence operator * (double d, const QuaternionSequence &qs) {
    Quaternion q(d);
    QuaternionSequence res(qs);
    for (auto it = res.data.begin(); it != res.data.end();) {
        it->second = q * it->second;
        if (!it->second)
            res.data.erase(it++);
        else
            ++it;
    }
    return res;
}

const Quaternion QuaternionSequence::operator[](const size_type i) const {
    auto iter = data.find(i);
    if (iter == data.end())
        return Quaternion();
    else
        return iter->second;
}

void QuaternionSequence::insert(const size_type n, const Quaternion &q) {
    if (q)
        data[n] = q;
    else
        data.erase(n);
}

bool QuaternionSequence::operator == (const QuaternionSequence& qs) const {
    if (data.size() != qs.data.size())
        return false;
        
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
    return data.size() > 0;
}

std::ostream& operator << (std::ostream& os, const QuaternionSequence& qs) {
    os << "(";
    for (auto i = qs.data.begin(); i != qs.data.end(); ++i) {
        if (i != qs.data.begin())
            os << ", ";
        os << i->first << " -> " << i->second;
    }
    os << ")";
    return os;
}

int QuaternionSequence::count() {
    return qs_number;
}
