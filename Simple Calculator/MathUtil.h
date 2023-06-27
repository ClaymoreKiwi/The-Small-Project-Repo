#pragma once
#include <string>

template <typename T1, typename T2>
void Add(T1 a, T2 b)
{
	auto sum = a + b;
	std::cout << sum << std::endl;
}

template <typename T1, typename T2>
void Subtract(T1 a, T2 b)
{
	auto difference = a - b;
	std::cout << difference << std::endl;
}

template <typename T1, typename T2>
void Multiply(T1 a, T2 b)
{
	auto product = a * b;
	std::cout << product << std::endl;
}

template <typename T1, typename T2>
void Divide(T1 a, T2 b)
{
	auto quotient = a / b;
	std::cout << quotient << std::endl;
}