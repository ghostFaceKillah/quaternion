#include <cassert>
#include <iostream>
#include "quaternion.h"

int main() {
    {
        Quaternion q;
        assert(q.R() == 0. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q(1.);
        assert(q.R() == 1. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q(0xFF);
        assert(q.R() == 255. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q('a');
        assert(q.R() == 97. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q(true);
        assert(q.R() == 1. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q = 1.;
        assert(q.R() == 1. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q = 0xFF;
        assert(q.R() == 255. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q = 'a';
        assert(q.R() == 97. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q = true;
        assert(q.R() == 1. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q(1., 2.);
        assert(q.R() == 1. && q.I() == 2. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q(1., 2., 3., 4.);
        assert(q.R() == 1. && q.I() == 2. && q.J() == 3. && q.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(q1);
        assert(q2.R() == 1. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2 = q1;
        assert(q2.R() == 1. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2;
        q2 = q1;
        assert(q2.R() == 1. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q;
        q = 1.;
        assert(q.R() == 1. && q.I() == 0. && q.J() == 0. && q.K() == 0.);
    }
    {
        Quaternion q1(1., 2., 3., 4.), q2, q3;
        q2 = q1.conj();
        assert(q2.R() == 1. && q2.I() == -2. && q2.J() == -3. && q2.K() == -4.);
        q3 = conj(q1);
        assert(q3.R() == 1. && q3.I() == -2. && q3.J() == -3. && q3.K() == -4.);
    }
    {
        Quaternion q(1., 2., 3., 4.);
        assert(q.norm() * norm(q) == 30.);
        assert(q * q.conj() == q.norm() * q.norm());
    }
    {
        Quaternion q1(1., 2., 3., 4.), q2;
        q2 = -q1;
        assert(q2.R() == -1. && q2.I() == -2. && q2.J() == -3. && q2.K() == -4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(8., 7., 6., 5.);
        q2 += q1;
        assert(q2.R() == 9. && q2.I() == 9. && q2.J() == 9. && q2.K() == 9.);
    }
    {
        Quaternion q(1., 2., 3., 4.);
        q += 1.;
        assert(q.R() == 2. && q.I() == 2. && q.J() == 3. && q.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(8., 7., 6., 5.);
        Quaternion q3 = q2 + q1;
        assert(q3.R() == 9. && q3.I() == 9. && q3.J() == 9. && q3.K() == 9.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2 = q1 + 1.;
        assert(q2.R() == 2. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2 = 1. + q1;
        assert(q2.R() == 2. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(8., 7., 6., 5.);
        q2 -= q1;
        assert(q2.R() == 7. && q2.I() == 5. && q2.J() == 3. && q2.K() == 1.);
    }
    {
        Quaternion q(1., 2., 3., 4.);
        q -= 1.;
        assert(q.R() == 0. && q.I() == 2. && q.J() == 3. && q.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(8., 7., 6., 5.);
        Quaternion q3 = q2 - q1;
        assert(q3.R() == 7. && q3.I() == 5. && q3.J() == 3. && q3.K() == 1.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2 = q1 - 1.;
        assert(q2.R() == 0. && q2.I() == 2. && q2.J() == 3. && q2.K() == 4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2 = 1. - q1;
        assert(q2.R() == 0. && q2.I() == -2. && q2.J() == -3. && q2.K() == -4.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(2., 3., 4., 5.);
        Quaternion q3(2., 4., 6., 8.);
        q1 += q2 += q3;
        assert(q1.R() == 5. && q1.I() == 9. && q1.J() == 13. && q1.K() == 17.);
        assert(q2.R() == 4. && q2.I() == 7. && q2.J() == 10. && q2.K() == 13.);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        Quaternion q2(2., 3., 4., 5.);
        Quaternion q3(2., 4., 6., 8.);
        assert(q1 + q2 == q2 + q1);
        assert((q1 + q2) + q3 == q1 + (q2 + q3));
    }
    {
        Quaternion q1(1., 2., 4., 8.);
        Quaternion q2(2., 3., 4., 5.);
        Quaternion q3(2., 4., 6., 8.);
        assert(q1 * q2 != q2 * q1);
        assert((q1 * q2) * q3 == q1 * (q2 * q3));
        assert((q1 + q2) * q3 == q1 * q3 + q2 * q3);
    }
    {
        Quaternion q1(1., 2., 3., 4.);
        assert(+q1 + -q1 == 0.);
        assert(-q1 == 0. - q1);
        assert(+q1 == q1);
    }
    {
        Quaternion q(1);
        if (q)
            assert(1);
        else
            assert(0);
    }
    {
        assert(I * I == -1);
        assert(J * J == -1);
        assert(K * K == -1);
        assert(I * J == K);
        assert(J * K == I);
        assert(K * I == J);
        assert(J * I == -K);
        assert(K * J == -I);
        assert(I * K == -J);
    }
    {
        Quaternion q1, q2(0., -1.5, 0., 3.), q3(7.222);
        // Wypisuje 0 -1.5i+3k 7.222
        ::std::cout << q1 << ' ' << q2 << ' ' << q3 << ::std::endl;
    }
}
