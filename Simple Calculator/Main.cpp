#include <iostream>
#include "MathUtil.h"
#include <string>

void print(std::string message)
{
	std::cout << message << std::endl;
}

int main()
{
	print("Welcome to the calculator");
	print("what would you like to do?");
	char menuSelection = ' ';
	print("1: Add");
	print("2: Subtract");
	print("3: Multiply");
	print("4: Divide");
	print("0 : exit");
	std::cin >> menuSelection;

	switch (menuSelection)
	{
	case'1':
	{
		print("Please enter the two numbers you'd like to add together");
		auto num1 = 0;
		print("First number:");
		std::cin >> num1;
		auto num2 = 0;
		print("Second number:");
		std::cin >> num2;
		Add(num1, num2);
		break;
	}
	case'2':
	{
		print("Please enter the two numbers you'd like to subtract together");
		auto num1 = 0;
		print("First number:");
		std::cin >> num1;
		auto num2 = 0;
		print("Second number:");
		std::cin >> num2;
		Subtract(num1, num2);
		break;
	}
	case'3':
	{
		print("Please enter the two numbers you'd like to multiply together");
		auto num1 = 0;
		print("First number:");
		std::cin >> num1;
		auto num2 = 0;
		print("Second number:");
		std::cin >> num2;
		Multiply(num1, num2);
		break;
	}
	case'4':
	{
		print("Please enter the two numbers you'd like to divide together");
		auto num1 = 0;
		print("First number:");
		std::cin >> num1;
		auto num2 = 0;
		print("Second number:");
		std::cin >> num2;
		Divide(num1, num2);
		break;
	}
	case'0':
		print("Thanks for using the calculator, good bye!");
		return 0;
	default:
		print("This is an invalid selection");
	}
}