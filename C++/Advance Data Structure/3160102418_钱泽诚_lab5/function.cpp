#include "head.h"

Fraction::Fraction(int a, int b)
{
	this->numerator = a;
	this->denominator = b;
	int g = gcd(a, b);
	if (g != 0)
	{
		this->denominator /= g;
		this->numerator /= g;
	}
}

Fraction::Fraction(const Fraction &f) //copy constructor
{
	numerator = f.numerator;
	denominator = f.denominator;
}

const Fraction Fraction::operator+(const Fraction &n) const
{
	Fraction tmp;
	tmp.denominator = denominator * n.denominator;
	tmp.numerator = denominator * n.numerator + numerator * n.denominator;
	int g = gcd(tmp.numerator, tmp.denominator);
	if (g != 0)
	{
		tmp.denominator /= g;
		tmp.numerator /= g;
	}
	return tmp;
}

const Fraction Fraction::operator-(const Fraction &n) const
{
	Fraction tmp;
	tmp.denominator = denominator * n.denominator;
	tmp.numerator = n.denominator * numerator - n.numerator * denominator;
	int g = gcd(tmp.numerator, tmp.denominator);
	if (g != 0)
	{
		tmp.denominator /= g;
		tmp.numerator /= g;
	}
	return tmp;
}

const Fraction Fraction::operator*(const Fraction &n) const
{
	Fraction tmp;
	tmp.denominator = denominator * n.denominator;
	tmp.numerator = n.numerator * numerator;
	int g = gcd(tmp.numerator, tmp.denominator);
	if (g != 0)
	{
		tmp.denominator /= g;
		tmp.numerator /= g;
	}
	return tmp;
}

const Fraction Fraction::operator/(const Fraction &n) const
{
	Fraction tmp;
	tmp.denominator = denominator * n.numerator;
	tmp.numerator = numerator * n.denominator;
	int g = gcd(tmp.numerator, tmp.denominator);
	if (g != 0)
	{
		tmp.denominator /= g;
		tmp.numerator /= g;
	}
	return tmp;
}

bool Fraction::operator<(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator < 0;
}

bool Fraction::operator<=(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator <= 0;
}

bool Fraction::operator==(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator == 0;
}

bool Fraction::operator!=(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator != 0;
}

bool Fraction::operator>=(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator >= 0;
}

bool Fraction::operator>(const Fraction &n) const
{
	Fraction tmp;
	tmp = *this - n;
	return tmp.numerator > 0;
}

string Fraction::toString()
{
	string tmp;
	tmp += to_string(numerator);
	tmp += "/";
	tmp += to_string(denominator);
	return tmp;
}

istream & operator>>(istream & in, Fraction& n)	//overload inserter
{
	string tmp, tmp_h, tmp_t;
	in >> tmp;
	int index = tmp.find("/");
	int i;
	for (i = 0; i <= index; i++)
		tmp_h += tmp[i];
	for (; i < tmp.size(); i++)
		tmp_t += tmp[i];
	int num, den;
	num = stoi(tmp_h);
	den = stoi(tmp_t);
	int g = gcd(num, den);
	if (g != 0)
	{
		num /= g;
		den /= g;
	}
	n.numerator = num;
	n.denominator = den;
	return in;
}

ostream& operator<<(ostream& out, Fraction& n)	//overload extractor
{
	out << n.toString();
	return out;
}

int Fraction::getNumerator() const
{
	return this->numerator;
}

int Fraction::getDenominator() const
{
	return this->denominator;
}

int gcd(int m, int n)
{
	for (int i = (m > n ? m : n); i >= 2; i--)
	{
		if (m % i == 0 && n % i == 0)
			return i;
	}
	return 0;
}