#include <iostream>
#include "Rational.h"

// Setting the nom to be 0 and the denom to be 1.
Rational::Rational() : nom(), denom(0) {

	this->denom.setCoeff(0, 1);
}

// With a given polynomials, setting the nom and the denom accordingly.
Rational::Rational(const Polynomial& p1, const Polynomial& p2) {

	this->nom = p1;
	this->denom = p2;
}

// Returning the nom.
Polynomial& Rational::getNom() {

	return this->nom;
}

// Returning the denom.
Polynomial& Rational::getDenom() {

	return this->denom;
}

// Printing the rational fraction operator.
ostream& operator<<(ostream& out, const Rational& r) {

	out << "numerator=" << r.nom;
	out << "--------------------------" << endl;
	out << "denominator=" << r.denom;
	return out;
}

// Multiplication of a given rational fraction and a given input number with * operator.
Rational& operator*(const double input, const Rational& r) {

	return r * input;
}

// Setting one rational fraction to be equal to a given fraction, with = operator.
Rational& Rational::operator=(const Rational& r) {

	this->nom = r.nom;
	this->denom = r.denom;
	return *this;
}

// Addition of two rational fraction with + operator.
Rational& Rational::operator+(const Rational& r) const {
	
	Rational* temp = new Rational(this->nom * r.denom + this->denom * r.nom, this->denom * r.denom);
	return *temp;
}

// Multiplication of two rational fractions with * operator.
Rational& Rational::operator*(const Rational& r) const {
	Rational* temp = new Rational(this->nom * r.nom, this->denom * r.denom);
	return *temp;
}

// Multiplication of a rational fraction with an input number with * operator.
Rational& Rational::operator*(const double input) const {

	Rational* temp = new Rational(this->nom * input, this->denom * input);
	return *temp;
}


// Printing the rational fraction.
void Rational::print() {
	nom.print();
	cout << "--------------------------" << endl;
	denom.print();
}