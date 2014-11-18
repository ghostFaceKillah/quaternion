#include <ostream> 
#include <map>
#include <vector>
#include "quaternion.h"

class QuaternionSequence {
	typedef int size_type;
	private:
		std::map<size_type, Quaternion> quaternions;
	
    public:
        QuaternionSequence();
        QuaternionSequence(std::map<size_type, Quaternion>&& q_map);
        QuaternionSequence(std::vector<Quaternion>&& q_vector);

        QuaternionSequence(const QuaternionSequence& qs);
        QuaternionSequence(QuaternionSequence&& qs); 
        
        QuaternionSequence& operator= (const QuaternionSequence& qs);
        QuaternionSequence& operator= (QuaternionSequence&& qs);

		QuaternionSequence& operator+=(const QuaternionSequence& qs);
		QuaternionSequence operator+ (const QuaternionSequence& qs);
		QuaternionSequence& operator-=(const QuaternionSequence& qs);
		QuaternionSequence operator- (const QuaternionSequence& qs);
		QuaternionSequence& operator*=(const Quaternion& q);
		/*do przemyślenia*/
		friend QuaternionSequence operator* (const Quaternion& q, const QuaternionSequence& qs);
		//Quaternion qs[QuaternionSequence::size_type];
		void insert(int n, const Quaternion& q);
		bool operator==(const QuaternionSequence& qs) const;
        bool operator!=(const QuaternionSequence& qs) const;
		explicit operator bool() const;
		friend std::ostream& operator<<(std::ostream& out, const QuaternionSequence& qs);
};
int count();

/* 
* I - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 1, 0, 0);
* J - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 0, 1, 0);
* K - globalny niemodyfikowalny obiekt reprezentujący kwaternion (0, 0, 0, 1).

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
