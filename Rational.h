#ifndef RATIONAL_H_
#define RATIONAL_H_
#include "Polynomial.h"

class Rational {

private:

	Polynomial nom, denom;

public:

	// Constructors
	Rational();
	Rational(const Polynomial&, const Polynomial&);

	// Getters
	Polynomial& getNom();
	Polynomial& getDenom();
	
	// Operators overload
	friend ostream& operator<<(ostream&, const Rational&);
	friend Rational& operator*(const double, const Rational&);
	Rational& operator=(const Rational&);
	Rational& operator+(const Rational&) const;
	Rational& operator*(const Rational&) const;
	Rational& operator*(const double) const;
	

	// Other member functions.
	void print();
};

#endif
