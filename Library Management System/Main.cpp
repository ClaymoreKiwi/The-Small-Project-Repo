#include <iostream>
#include <string>
#include <unordered_map>


//helper print function to reduce typing messages
void Print(std::string message)
{
	std::cout << message << "\n";
}

class library
{
public:
	library() {};

	void AddBook(const std::string& pos, const std::string& bookName)
	{
		//check if there are no books to be able to add in immidiately
		if (m_books.size() == NULL)
		{
			m_books.insert({pos, bookName});
			//Print("Book added!");
			return;
		}

	}
	void RemoveBook(const std::string& pos)
	{

	}
	std::string FindBook(const std::string& pos)
	{

	}
	void AllBooks()
	{

	}
private:
	std::unordered_map<std::string, std::string> m_books;

};

int main()
{
	using namespace std;
	library myLib;
	char userChoice = ' ';

	Print("Welcome to the library, please select an option by number");
	Print("1: Add New book");
	Print("2: Remove book");
	Print("3: find book");
	Print("4: Get a list of all books");
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
			//myLib.RemoveBook(auther);
			break;
		case'3':
			//myLib.FindBook(auther);
			break;
		case'4':
			//myLib.AllBooks();
			break;
		default:
			Print("this is an invalid option");
			break;
	}

	cin.get();
}