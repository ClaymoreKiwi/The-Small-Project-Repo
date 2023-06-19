#pragma once
#include <unordered_map>
#include "Print.h"

class library
{
public:
	library() {};

	void AddBook(const std::string& BookID, const std::string& bookName)
	{

		if (m_books.find(BookID) != m_books.end())
		{
			Print("Sorry this book already exists!");
			Print("Please choose another option in the menu");
			return;
		}
		m_books.emplace(BookID, bookName);
		Print("Book added!");
		Print("Press Enter to return to menu");
		std::cin.get();
	}
	void RemoveBook(const std::string& BookID)
	{
		if (m_books.size() == NULL)
		{
			Print("There are no books to remove!");
			Print("Press Enter to return to menu");
			std::cin.get();
			return;
		}
		if (m_books.find(BookID) == m_books.end())
		{
			Print("This book does not exist, cannot remove!");
			Print("Press Enter to return to menu");
			std::cin.get();
			return;
		}
		m_books.erase(BookID);
		Print("Book has been removed!");
		Print("Press Enter to return to menu");
		std::cin.get();
	}
	void FindBook(const std::string& BookID)
	{
		if (m_books.find(BookID) != m_books.end())
		{
			Print(m_books.at(BookID));
			Print("Press Enter to return to menu");
			std::cin.get();
			return;
		}
		else
		{
			Print("Book is not in the library, you can add it through the menu");
			Print("Press Enter to return to menu");
			std::cin.get();
			return;
		}
	}
	void AllBooks()
	{
		for (const auto& pair : m_books)
		{
			Print(pair.first + " : " + pair.second);
		}
	}
private:
	std::unordered_map<std::string, std::string> m_books;

};