#include <iostream>
#include "Polynomial.h"

// Defining max degree to be 0.
int Polynomial::maxDegree = 0;

// Defualt constructor - degree is 0.
Polynomial::Polynomial() : coeff(NULL), degree(0), defaultCoeff(12345) {}

// Constructor with a given input to be the degree.
Polynomial::Polynomial(int input) : degree(input), defaultCoeff(12345) {
	
	int i;
	this->coeff = new double[input + 1];
	for (i = 0; i <= input; i++) {
		this->coeff[i] = 0;
	}
}

// Constructor copying values from a given array and given degree.
Polynomial::Polynomial(double* arr, int input) : degree(input), defaultCoeff(12345) {

	int i;
	this->coeff = new double[input + 1];
	
	// Copying the values
	for (i = 0; i <= input; i++) {
		this->coeff[i] = arr[i];
		if (arr[i] && i > maxDegree) {
			maxDegree = i;
		}
	}
}

// Copy constructor - "smart copying" of the values from one polynomial to another.
Polynomial::Polynomial(const Polynomial& p) : defaultCoeff(12345) {

	this->degree = p.degree;
	if (!p.coeff) {
		this->coeff = NULL;
	}
	else {
		this->coeff = new double[this->degree + 1];
		for (int i = 0; i <= this->degree; i++) {
			this->coeff[i] = p.coeff[i];
		}
	}
}

// Destructor
Polynomial::~Polynomial() {
	
	if (coeff){
		delete [] this->coeff;
		this->coeff = NULL;
	}
	
}

// By the different true or false input, we return the actual degree, or the degree with coeffs different from zero.
int Polynomial::getDegree(bool curr) const {

	if (!curr) {
		return this->degree;
	}
	else {
		return getDegree();
	}
}

// Returning the actual degree that the coeff is different from zero.
int Polynomial::getDegree() const {

	int i, currIndex = 0;
	for (i = 0; i <= this->degree; i++) {
		if (this->coeff[i]) {
			currIndex = i;
		}
	}
	return currIndex;
}

// Setting a coeff with a given degree and value of coeff.
Polynomial& Polynomial::setCoeff(int degree, double coeff) {

	this->coeff[degree] = coeff;
	return *this;
}

// Returning a coeff, returning different options depends on the index input.
double Polynomial::getCoeff(int index) const {

	// Index is negative
	if (index < 0) {
		return 56789;
	}
	
	if (index > this->degree && index > maxDegree) {
		return 0;
	}
	if (index > this->degree && index <= maxDegree) {
		return 56789;
	}

	// No condition existed, returning the coeff without problems.
	return this->coeff[index];
}


// Returning current max degree.
int Polynomial::getMaxDegree() {

	return maxDegree;
}

// Setting one polynomial to be equal to another with operator =.
Polynomial& Polynomial::operator=(const Polynomial& p) {

	int i;
	if (this->coeff) {
		delete[] this->coeff;
	}
	this->coeff = new double[p.degree + 1];
	this->degree = p.degree;

	for (i = 0; i <= p.degree; i++) {
		this->coeff[i] = p.coeff[i];
	}
	return *this;
}

// Addition of two polynomials by the + operator.
Polynomial& Polynomial::operator+(const Polynomial& p) const {

	int i, max;

	// Checking the max degree between the two polynomials.
	p.degree >= this->degree ? max = p.degree : max = this->degree;

	// Creating a new polynomial
	Polynomial* p1 = new Polynomial(max);

	// Copying the added coeffs to the new temp polynomial.
	for (i = 0; i <= degree && i <= p.degree && p.coeff && this->coeff; i++) {
		p1->coeff[i] = coeff[i] + p.coeff[i];
	}

	// If one polynomial is bigger than the other, copying the left coeffs.
	while (i <= degree && coeff) {
		p1->coeff[i] = this->coeff[i];
		i++;
	}
	while (i <= p.degree && p.coeff) {
		p1->coeff[i] = p.coeff[i];
		i++;
	}
	return *p1;
}

// Subtraction between two polynomials with the - operator.
Polynomial& Polynomial::operator-(const Polynomial& p) const {

	int i, max;

	// Checking the max degree between two polynomials.
	p.degree >= this->degree ? max = p.degree : max = this->degree;

	// Creating a new temp polynomial.
	Polynomial* poly = new Polynomial(max);

	// Copying the coeffs after subtraction.
	for (i = 0; i <= degree && i <= p.degree; i++) {
		poly->coeff[i] = this->coeff[i] - p.coeff[i];
	}

	// If one polynomial is bigger than the other, copying the left coeffs.
	while (i <= degree) {
		poly->coeff[i] = this->coeff[i];
		i++;
	}
	while (i <= p.degree) {
		poly->coeff[i] = -p.coeff[i];
		i++;
	}
	return *poly;
}

// Multiplication between two polynomials with the * operator.
Polynomial& Polynomial::operator*(const Polynomial& p) const {

	int i, j;

	// Creating a temp polynomial with the degrees of both.
	Polynomial* poly = new Polynomial(this->degree + p.degree);
	
	// Copying the coeffs after multiplication.
	for (i = 0; i <= this->degree; i++) {
		for (j = 0; j <= p.degree; j++) {
			poly->coeff[i + j] += this->coeff[i] * p.coeff[j];
			if (poly->coeff[i + j] && i + j > maxDegree)
				maxDegree = i + j;
		}
	}
	return *poly;
}

// Multliplication of a polynomial with an input number.
Polynomial& Polynomial::operator*(const double input) const {

	int i;
	Polynomial* poly = new Polynomial();
	*poly = *this;
	
	for (i = 0; i <= this->degree; i++) {
		poly->coeff[i] *= input;
	}
	return *poly;
}

// Printing operator overload
ostream& operator<<(ostream& out, const Polynomial& p) {

	int i, max = 0;
	out << "Polynomial = ";

	if (!p.coeff && !p.degree) {
		out << "0" << endl;
		return out;
	}
	for (i = 0; i <= p.degree; i++) {
		if (p.coeff[i] && i > max) {
			max = i;
		}
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!p.coeff[i]) {
				out << "0";
			}
			else {
				out << p.coeff[i];
			}
		}
		else {
			out << "+";
			if (!p.coeff[i]) {
				out << "(0)";
			}
			else {
				out << "(" << p.coeff[i] << ")";
			}
			out << "*X^" << i;
		}
	}
	out << endl;
	return out;
}

// Multiplication of a given polynimal with an input number.
Polynomial& operator*(const double input, const Polynomial& p) {

	return p * input;
}

// Returning direct coeff value with a given index.
double& Polynomial::operator[](int const index) {

	if (index < 0 || index > this->degree) {
		return defaultCoeff;
	}
	return this->coeff[index];
}

// Printing the polynomial.
void Polynomial::print() const {

	cout << "Polynomial = ";

	// Checking if we need to print the 0 polynomial.
	if (!this->coeff && !this->degree) {
		cout << "0" << endl;
		return;
	}

	int i, max = 0;
	// Checking the max degree with coeff different from 0.
	for (i = 0; i <= this->degree; i++) {
		if (this->coeff[i] && i > max) {
			max = i;
		}
	}

	// Checking if the coeff isn't 0.
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!(this->coeff[i])) {
				cout << "0";
			}
			else {
				cout << this->coeff[i];
			}
		}
		else {
			cout << "+";
			if (!this->coeff[i]) {
				cout << "(0)";
			}
			else {
				cout << "(" << this->coeff[i] << ")";
			}
			cout << "*X^" << i;
		}
	}
	cout << endl;
}

