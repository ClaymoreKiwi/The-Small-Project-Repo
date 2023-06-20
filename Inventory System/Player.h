#pragma once
#include "InventoryItem.h"
#include <vector>
#include <iostream>
#include <algorithm>

class P_Player
{
public:
	P_Player()
	{
		//initialise inventory size to 10 and set all to empty items
		I_Item emptyslot(0, "empty");
		for (; Inventory.size() < 10; )
			Inventory.push_back(emptyslot);
	};
	void PAddToInventory(const I_Item& itemToAdd)
	{
		//count the empty slots
		int emptyCount = 0;
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i].m_ItemName == "empty")
				emptyCount++;
		}
		//replace empty slots with item added
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i].m_ItemName == "empty")
			{
				Inventory[i].m_ItemName = itemToAdd.m_ItemName;
				Inventory[i].m_AdjustedValue = itemToAdd.m_AdjustedValue;
				return;
			}
		}
		//if all the inventory slots are taken add a new slot
		if (emptyCount == 0)
		{
			Inventory.push_back(itemToAdd);
			std::cout << "item " << itemToAdd.m_ItemName << " has been added\n";
			return;
		}

	}
	void PRemoveFromInventory(const std::string& itemtoremove)
	{
		bool isItemPresent = false;
		//remove the item if the name matches the item to remove
		for (int i = 0; i < Inventory.size() ; ++i)
		{
			if (Inventory[i].m_ItemName == itemtoremove)
			{
				Inventory[i].m_ItemName = "empty";
				Inventory[i].m_AdjustedValue = 0;
				std::cout << "item has been removed";
				isItemPresent = true;
				return;
			}
		}
		if (!isItemPresent)
		{
			std::cout << "item was not in your inventory\n";
		}
	}

	void PGetInventory() const
	{
		for (auto& item : Inventory)
		{
			if (item.m_ItemName != "empty")
				std::cout << item.m_ItemName << "\n";
		}
	}
	struct PSortingKey
	{
		//overloaded operator to sort the items by value
		inline bool operator()(const I_Item& item1, const I_Item& item2)
		{
			return(item1.m_AdjustedValue < item2.m_AdjustedValue);
		}
	};
	void PsortInventory()
	{
		int notemptyCount = 0;
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i].m_ItemName != "empty")
				notemptyCount++;
		}
		static bool isSorted = false;  // Add a static flag to track if the inventory is sorted

		if (notemptyCount > 0 && !isSorted)  // Only sort if there are items and the inventory is not already sorted
		{
			std::sort(Inventory.begin(), Inventory.end(), PSortingKey());
			isSorted = true;  // Set the flag to true after sorting
		}
	}
	
	std::string PFindItem(const std::string& name)
	{
		for (int i = 0; i < Inventory.size(); ++i)
		{
			if (Inventory[i].m_ItemName == name)
				return name;
		}
		return "not found";
	}

private:
	std::vector<I_Item> Inventory;
};