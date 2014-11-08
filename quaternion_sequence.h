#include<ostream> 

class Quaternion {
        float re, i, j, k;
    public:
        // constructors
        Quaternion();
        Quaternion(float re);
        Quaternion(float re, float im);
        Quaternion(float a, float b, float c, float d);
        Quaternion(Quaternion& s1); 
        // we need to look into how copying constructor is made
        //  Quaternion q2(q1) - tworzy kopię kwaternionu q1;
        //  Quaternion q2 = q1 - tworzy kopię kwaternionu q1;

        // operators
        Quaternion operator+ ();
        Quaternion operator- ();

        Quaternion& operator+=(const Quaternion& param);
        Quaternion& operator-=(const Quaternion& param);
        Quaternion& operator*=(const Quaternion& param);

        Quaternion operator+ (const Quaternion& param);
        /*
        const MyClass MyClass::operator+(const MyClass &other) const {
            MyClass result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
            result += other;            // Use += to add other to the copy.
            return result;              // All done!
        }
        const MyClass MyClass::operator+(const MyClass &other) const {
            return MyClass(*this) += other;
        }
        */

        Quaternion operator- (const Quaternion& param);
        Quaternion operator* (const Quaternion& param);
        Quaternion operator= (const Quaternion& param);
        /*
        MyClass& MyClass::operator=(const MyClass &rhs) {
            // 1.  Deallocate any memory that MyClass is using internally
            // 2.  Allocate some memory to hold the contents of rhs
            // 3.  Copy the values from rhs into this instance
            // 4.  Return *this
        } 
          MyClass& MyClass::operator=(const MyClass &rhs) {
              // Check for self-assignment!
              if (this == &rhs)      // Same object?
                return *this;        // Yes, so skip assignment, and just return *this.
              // ... // Deallocate, allocate new space, copy values...
              return *this;
        }
              
        */

        bool operator==(const Quaternion& other) const;
        /*
        bool MyClass::operator==(const MyClass &other) const;
        */
        bool operator!=(const Quaternion& other) const;

        friend std::ostream& operator<<(std::ostream& out, const Quaternion& q);

        // setters getters
        float R();
        float I();
        float J();
        float K();
        Quaternion conj();
        Quaternion conj(Quaternion q);
        float norm();
        // (norma a + bi + cj + dk to sqrt(a*a + b*b + c*c + d*d));
};


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
