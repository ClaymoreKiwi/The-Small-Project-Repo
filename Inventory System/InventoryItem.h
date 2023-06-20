#pragma once
//simple item class to be able to store objects
#include <string>
class I_Item
{
public:
	I_Item(int damage, std::string ItemName) 
		: m_AdjustedValue(damage), m_ItemName(ItemName){};

	~I_Item() {};
public:
	int m_AdjustedValue;
	std::string m_ItemName;
};
