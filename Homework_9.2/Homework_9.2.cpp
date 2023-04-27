﻿// Homework_9.2.cpp 

#include <iostream>
#include <string>
#include <windows.h>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator+(Fraction other) 
	{
		Fraction temp = *this;
		temp.numerator_ = (numerator_ * other.denominator_) + (other.numerator_*denominator_);
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}

	Fraction operator-(Fraction other)
	{
		Fraction temp = *this;
		temp.numerator_ = (numerator_ * other.denominator_) - (other.numerator_ * denominator_);
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}

	Fraction operator*(Fraction other)
	{
		Fraction temp = *this;
		temp.numerator_ = numerator_ * other.numerator_;
		temp.denominator_ = denominator_ * other.denominator_;
		return temp;
	}

	Fraction operator/(Fraction other)
	{
		Fraction temp = *this;
		temp.numerator_ = numerator_ * other.denominator_;
		temp.denominator_ = denominator_ * other.numerator_;
		return temp;
	}

	Fraction operator++()
	{
		Fraction temp = *this;
		temp.numerator_ = numerator_ + denominator_;
		temp.denominator_ = denominator_;
		return temp;
	}

	Fraction operator--(int)
	{
		Fraction temp = *this;
		temp.numerator_ = numerator_ - denominator_;
		temp.denominator_ = denominator_;
		return temp;
	}

	std::string print_() 
	{
		std::string temp = std::to_string(this->numerator_) + "/" + std::to_string(this->denominator_);
		return(temp);
	};

	
};

int main()
{
	int a, b;
	system("chcp 1251");
	system("cls");

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> b;

	Fraction f1(a, b);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> a;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> b;

	Fraction f2(a, b);

	std::cout << f1.print_() << " + " << f2.print_() << " = " << (f1+f2).print_() << '\n';
	std::cout << f1.print_() << " - " << f2.print_() << " = " << (f1 - f2).print_() << '\n';
	std::cout << f1.print_() << " * " << f2.print_() << " = " << (f1 * f2).print_() << '\n';
	std::cout << f1.print_() << " / " << f2.print_() << " = " << (f1 / f2).print_() << '\n';
	std::cout << "++" << f1.print_() << " * " << f2.print_() << " = " << (++f1 * f2).print_() << '\n';
	std::cout << "Значение дроби 1 = " << (++f1).print_() << std::endl;
	std::cout << (++f1).print_() << "--" << " * " << f2.print_() << " = " << ((++f1--) * f2).print_() << '\n';
	std::cout << "Значение дроби 1 = " << (++f1--).print_() << std::endl;

	return 0;
}