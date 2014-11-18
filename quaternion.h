#include <ostream> 

class Quaternion {
        double re, i, j, k;
    public:
        // constructors
        Quaternion();
        Quaternion(double re);
        Quaternion(double re, double im);
        Quaternion(double a, double b, double c, double d);
        Quaternion(const Quaternion& q);
        Quaternion(Quaternion&& q); 

        // operators
        Quaternion operator+ ();
        Quaternion operator- ();

        // consider adding static designator to following operators
        Quaternion& operator+=(const Quaternion& param);
        Quaternion& operator-=(const Quaternion& param);
        Quaternion& operator*=(const Quaternion& param);
        Quaternion operator+ (const Quaternion& param);
        Quaternion operator- (const Quaternion& param);
        Quaternion operator* (const Quaternion& param);
        Quaternion& operator= (const Quaternion& param);
        Quaternion& operator= (Quaternion&& param);
        bool operator==(const Quaternion& other) const;
        bool operator!=(const Quaternion& other) const;

        friend std::ostream& operator<<(std::ostream& out, const Quaternion& q);

        // getters
        double R() const;
        double I() const;
        double J() const;
        double K() const;
        double norm() const;
        Quaternion conj();
        // (norma a + bi + cj + dk to sqrt(a*a + b*b + c*c + d*d));
};

double norm(const Quaternion& q);
Quaternion conj(const Quaternion& q);


/* 
* if(q), while(q) - warunek jest spełniony, gdy kwaternion nie jest
równy zeru;
* os << q - wypisuje kwaternion q na strumień os;
* I - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 1, 0, 0);
* J - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 0, 1, 0);
* K - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 0, 0, 1).

Do reprezentacji składowych kwaternionu można użyć typu double.

= Klasa QuaternionSequence =
Klasa ta powinna implementować ciągi kwaternionów prawie wszędzie
równe zeru. Powinny być dostępne następujące instrukcje:
* QuaternionSequence qs - tworzy ciąg kwaternionów wszędzie równy zeru;
* QuaternionSequence qs(m) - tworzy ciąg kwaternionów na podstawie mapy m,
która jest typu std::map<QuaternionSequence::size_type, Quaternion>,
klucze mapy oznaczają numery wyrazów w ciągu;
* QuaternionSequence qs(v)- tworzy ciąg kwaternionów na podstawie wektora v,
który jest typu std::vector<Quaternion>, kolejne elementy wektora
oznaczają wartości wyrazów ciągu dla indeksów 0, 1, 2, ...;
* QuaternionSequence qs2(qs1) - tworzy kopię ciągu kwaternionów qs1;
* QuaternionSequence qs2 = qs1 - tworzy kopię ciągu kwaternionów qs1;
* qs2 = qs1 - przypisuje ciąg kwaternionów qs1 na zmienną qs2;
* qs1 += qs2 - dodaje do kolejnych wyrazów ciągu qs1 wyrazy ciągu qs2;
* qs1 + qs2 - zwraca ciąg kwaternionów, którego kolejne wyrazy są
* qs1 -= qs2 - odejmuje od kolejnych wyrazów ciągu qs1 wyrazy ciągu qs2;
* qs1 - qs2 - zwraca ciąg kwaternionów, którego kolejne wyrazy są
różnicami wyrazów z ciągów qs1 i qs2;
* qs *= q - mnoży wszystkie wyrazy ciągu qs przez kwaternion q;
* qs * q, q * qs - zwraca ciąg kwaternionów, którego kolejne wyrazy są
wyrazami ciągu qs pomnożonymi przez kwaternion q;
* qs[n] - zwraca kwaternion będący n-tym wyrazem ciągu qs (nie
                                                           oznacza to możliwości przypisania qs[n] = ...);
* insert(n, q) - wstawia kwaternion q na pozycję n;
* qs1 == qs2 - zwraca true, wtw. gdy ciągi qs1 i qs2 są równe,
tzn. mają równe kolejne wyrazy;
* qs1 != qs2 - zwraca true wtw. gdy ciągi qs1 i qs2 są różne;
* if(qs), while(qs) - warunek jest spełniony, gdy ciąg qs nie jest
wszędzie równy zeru;
* count() - zwraca liczbę aktualnie istniejących obiektów typu
QuaternionSequence;
* os << qs - wypisuje ciąg qs na strumień os.
*/
