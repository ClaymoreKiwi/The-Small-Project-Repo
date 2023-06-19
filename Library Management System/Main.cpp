#include "Library.h"

int main()
{
	using namespace std;
	library myLib;
	char userChoice = ' ';

	Print("Welcome to the library, please select an option by number");
	while (userChoice != '5')
	{
		Print("1: Add New book");
		Print("2: Remove book");
		Print("3: find book");
		Print("4: Get a list of all books");
		Print("5: Exit Program\n");
		cin >> userChoice;

		string auther = "";
		string bookName = "";
		//using user input to choose an action
		switch (userChoice)
		{
		case'1':
			Print("What book would you like to add into the library?");
			Print("Name of book");
			cin >> bookName;
			Print("Auther Name");
			cin >> auther;
			myLib.AddBook(auther, bookName);
			break;
		case'2':
			myLib.RemoveBook(auther);
			break;
		case'3':
			Print("Please enter the auther of the book youd like to find");
			cin >> auther;
			myLib.FindBook(auther);
			break;
		case'4':
			myLib.AllBooks();
			Print("Press Enter to return to menu");
			cin.get();
			break;
		default:
			Print("this is an invalid option\n");
			break;
		}
	}
	cin.get();
}