#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
using namespace std;

class Polynomial {

private:

	double* coeff;
	int degree;
	double defaultCoeff;
	static int maxDegree;

public:

	// Constructors
	Polynomial();
	Polynomial(int);
	Polynomial(double*, int);
	Polynomial(const Polynomial&);

	// Destructor
	~Polynomial();

	// Getters and setters
	int getDegree(bool) const;
	int getDegree() const;
	Polynomial& setCoeff(int, double);
	double getCoeff(int) const;
	static int getMaxDegree();

	// Operators overload.
	Polynomial& operator=(const Polynomial&);
	Polynomial& operator+(const Polynomial&) const;
	Polynomial& operator-(const Polynomial&) const;
	Polynomial& operator*(const Polynomial&) const;
	Polynomial& operator*(const double) const;
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend Polynomial& operator*(const double, const Polynomial&);
	double& operator[](int const);

	// Other member functions.
	void print() const;
};

#endif
