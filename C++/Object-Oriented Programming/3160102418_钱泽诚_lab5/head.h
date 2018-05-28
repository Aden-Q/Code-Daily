#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <string>

using namespace std;

class Fraction
{
public:
	Fraction() :numerator(1), denominator(1) {};	                             //default constructor
	Fraction(int a, int b);														 //overload constructor
	~Fraction() {};                                                              //destructor
	Fraction(const Fraction &f);                                                 //copy constructor
	const Fraction operator+(const Fraction &n) const;                           //overload operator "+"
	const Fraction operator-(const Fraction &n) const;                           //overload operator "-"
	const Fraction operator*(const Fraction &n) const;                           //overload operator "*"
	const Fraction operator/(const Fraction &n) const;                           //overload operator "/"
	bool operator<(const Fraction &n) const;                                     //overload operator "<"
	bool operator<=(const Fraction &n) const;                                    //overload operator "<="
	bool operator==(const Fraction &n) const;                                    //overload operator "=="
	bool operator!=(const Fraction &n) const;                                    //overload operator "!="
	bool operator>=(const Fraction &n) const;                                    //overload operator ">"
	bool operator>(const Fraction &n) const;                                     //overload operator ">="
	explicit operator double() const { return double(numerator) / double(denominator); }; //overload type converter
	string toString();
	friend istream & operator>>(istream & in, Fraction& n);		//overload inserter
	friend ostream& operator<<(ostream& out, Fraction& n);		//overload extractor
	int getNumerator() const;
	int getDenominator() const;

private:
	int numerator;
	int denominator;
};

int gcd(int m, int n);

#endif