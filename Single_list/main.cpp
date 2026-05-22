#include <iostream>
#include "List.h"

int main()
{
	List<int> list;

	while (true)
	{
		short user_choice;

		std::cout <<
			"======== MENU ========\n" <<
			"1. AddToHead\n" <<
			"2. AddToTail\n" <<
			"3. DeleteFromHead\n" <<
			"4. DeleteFromTail\n" <<
			"5. DeleteAll\n" <<
			"6. Show\n" <<
			"0. Exit\n" <<
			"> ";
		std::cin >> user_choice;

		switch (user_choice)
		{
		case 1:
			int value1;
			std::cout << "Enter value: ";
			std::cin >> value1;
			list.AddToHead(value1);
			break;

		case 2:
			int value2;
			std::cout << "Enter value: ";
			std::cin >> value2;
			list.AddToTail(value2);
			break;

		case 3:
			list.DeleteFromHead();
			std::cout << "Item deleted\n";
			break;

		case 4:
			list.DeleteFromTail();
			std::cout << "Item deleted\n";
			break;

		case 5:
			list.DeleteAll();
			std::cout << "Items deleted\n";
			break;

		case 6:
			list.Show();
			break;

		case 0:
			return 0;

		default:
			std::cout << "Unknown option!\n";
			break;
		}
	}
}