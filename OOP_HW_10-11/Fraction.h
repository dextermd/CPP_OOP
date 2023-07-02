#pragma once
class Fraction
{

private:

	int numerator;
	int denominator;

	void correct();

public:

	Fraction();
	Fraction(const int a, const int b);

	void show() const;
	static void show(const Fraction* arr, const int size);

	void init();

	int get_numerator() const;
	void set_numerator(const int numerator);

	int get_denominator() const;
	void set_denominator(const int denominator);

	Fraction(const char* str);

	Fraction arithmetic_operations(const Fraction& obj, char operation) const;

	Fraction operator+(const Fraction& obj) const;
	Fraction operator-(const Fraction& obj) const;
	Fraction operator*(const Fraction& obj) const;
	Fraction operator/(const Fraction& obj) const;

	~Fraction();
};

