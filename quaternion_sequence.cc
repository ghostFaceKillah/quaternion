#include <map>
#include <vector>
#include <iostream>
#include "quaternion_sequence.h"

int QuaternionSequence::how_many = 0;
const std::string SEQUENCE_START = "(";
const std::string SEQUENCE_END = ")";
const std::string ARROW = " -> ";
const std::string SEPARATOR = ", ";
const int DO_USUNIECIA = 0;

QuaternionSequence::QuaternionSequence()
{
    how_many++;
}

QuaternionSequence::~QuaternionSequence()
{
    how_many--;
}

QuaternionSequence::QuaternionSequence(const std::map<QuaternionSequence::size_type, Quaternion> &map)
{
    how_many++;
    quaternions = std::map<QuaternionSequence::size_type, Quaternion>(map);
}


QuaternionSequence::QuaternionSequence(const std::vector<Quaternion> &v)
{
    how_many++;
    int i = 0;
    for (Quaternion quaternion : v)
    {
        if (quaternion)
            quaternions[i] = quaternion;
        i++;
    }
}


QuaternionSequence::QuaternionSequence(const QuaternionSequence &qs)
{
    how_many++;
    quaternions = std::map<QuaternionSequence::size_type, Quaternion>(qs.quaternions);
}

QuaternionSequence::QuaternionSequence (QuaternionSequence &&qs) : quaternions(std::move(qs.quaternions)){
    how_many++;
}


QuaternionSequence& QuaternionSequence::operator=(const QuaternionSequence &qs1)
{
   quaternions = qs1.quaternions;
   return *this;
};

QuaternionSequence& QuaternionSequence::operator=(QuaternionSequence &&qs){
    quaternions = std::move(qs.quaternions);
    return *this;
}


QuaternionSequence& QuaternionSequence::operator+=(const QuaternionSequence &qs)
{
    for (auto iterator : qs.quaternions)
    {
        quaternions[iterator.first] += iterator.second;
        /* usuwam niepotrzebne (zerowe) kwaterniony */
        if (!quaternions[iterator.first])
        {
            quaternions.erase(iterator.first);
        }
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator+(const QuaternionSequence &qs) const{
    return QuaternionSequence(*this) += qs;
}

QuaternionSequence& QuaternionSequence::operator-=(const QuaternionSequence &qs)
{
    for (auto iterator : qs.quaternions)
    {
        quaternions[iterator.first] -= iterator.second;
        /* usuwam niepotrzebne (zerowe) kwaterniony */
        if (!quaternions[iterator.first]) {
            quaternions.erase(iterator.first);
        }
    }
    return *this;
}

const QuaternionSequence QuaternionSequence::operator-(const QuaternionSequence &qs) const{
    return QuaternionSequence(*this) -= qs;
}

QuaternionSequence& QuaternionSequence::operator*=(const Quaternion &q)
{
    for (auto iterator : this->quaternions)
    {
        quaternions[iterator.first] *= q;
        if (!quaternions[iterator.first])
            quaternions.erase(iterator.first);
    }
    return (*this);
}

const QuaternionSequence QuaternionSequence::operator*(const Quaternion &q) const{
    return QuaternionSequence(*this) *= q;
}

QuaternionSequence& QuaternionSequence::operator*=(const QuaternionSequence &qs)
{
    for (auto it = quaternions.begin(); it != quaternions.end();){
            auto tmp = *it;
            it ++;
            insert(tmp.first, tmp.second * qs[tmp.first]);
        }
        return *this;
}

const QuaternionSequence QuaternionSequence::operator*(const QuaternionSequence &qs)
{
    return(QuaternionSequence(*this) *= qs);
}

const Quaternion QuaternionSequence::operator[](const size_type i) const{
    auto iterator = quaternions.find(i);
    if (iterator == quaternions.end())
    {
        return Quaternion();
    }
    else
    {
        return iterator->second;
    }
}

void QuaternionSequence::insert(const size_type n, const Quaternion &q)
{
    if (q)
        quaternions[n] = q;
    else
        quaternions.erase(n);
}

bool QuaternionSequence::operator==(QuaternionSequence const &qs) const{
    if (this->quaternions.size() != qs.quaternions.size())
        return false;
    auto iterator = qs.quaternions.begin();
    for (auto quaternion : this->quaternions)
    {
        if (*iterator != quaternion)
            return false;
        iterator++;
    }
    return true;
}

bool QuaternionSequence::operator!=(QuaternionSequence const &qs) const{
    return !operator==(qs);
}

QuaternionSequence::operator bool() const
{
    return quaternions.size() > 0;
}

int QuaternionSequence::count()
{
    return how_many;
}

std::ostream& operator<<(std::ostream& out, const QuaternionSequence &qs)
{
    bool is_first = true;
    out << SEQUENCE_START;
    for (auto iterator : qs.quaternions)
    {
        if (is_first)
            is_first = false;
        else
            out << SEPARATOR;
        out << iterator.first << ARROW << iterator.second;
    }
    out << SEQUENCE_END;
    return out;
}

const QuaternionSequence operator*(const Quaternion& q, const QuaternionSequence& qs){
    return qs * q;
}


