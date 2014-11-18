#include <iostream>
#include <map>
#include <vector>
#include "quaternion_sequence.h"

QuaternionSequence::QuaternionSequence() {}
QuaternionSequence::QuaternionSequence(std::map<QuaternionSequence::size_type, Quaternion>&& q_map){}
QuaternionSequence::QuaternionSequence(std::vector<Quaternion>&& q_vector){}

QuaternionSequence::QuaternionSequence(const QuaternionSequence& qs){}
QuaternionSequence::QuaternionSequence(QuaternionSequence&& qs){}

QuaternionSequence& QuaternionSequence::operator= (const QuaternionSequence& qs){}
QuaternionSequence& QuaternionSequence::operator= (QuaternionSequence&& qs){}

QuaternionSequence& QuaternionSequence::operator+=(const QuaternionSequence& qs){}
QuaternionSequence QuaternionSequence::operator+ (const QuaternionSequence& qs){}
QuaternionSequence& QuaternionSequence::operator-=(const QuaternionSequence& qs){}
QuaternionSequence QuaternionSequence::operator- (const QuaternionSequence& qs){}
QuaternionSequence& QuaternionSequence::operator*=(const Quaternion& q){}
/*do przemyślenia*/
QuaternionSequence operator* (const Quaternion& q, const QuaternionSequence& qs){}
//Quaternion QuaternionSequence::qs[QuaternionSequence::size_type]{}
void insert(int n, const Quaternion& q){}
bool QuaternionSequence::operator==(const QuaternionSequence& qs) const{}
bool QuaternionSequence::operator!=(const QuaternionSequence& qs) const{}
QuaternionSequence::operator bool() const{}
std::ostream& operator<<(std::ostream& out, const QuaternionSequence& qs){}

int count(){}
