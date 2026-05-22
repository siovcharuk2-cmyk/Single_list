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
			"7. Insert\n" <<
			"8. DeleteAt\n" <<
			"9. Find\n" <<
			"10. FindAndChange\n" <<
			"11. Reverse\n" <<
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

		case 7:
			int value3,
				index;
			std::cout << "Enter value: ";
			std::cin >> value3;
			std::cout << "Enter index: ";
			std::cin >> index;
			list.Insert(value3, index);
			break;

		case 8:
			int index2;
			std::cout << "Enter index: ";
			std::cin >> index2;
			list.DeleteAt(index2);
			break;

		case 9:
			int value4;
			std::cout << "Enter value: ";
			std::cin >> value4;
			std::cout << "Index: " << list.Find(value4) << std::endl;
			break;

		case 10:
			int value5,
				value6;
			std::cout << "Enter value: ";
			std::cin >> value5;
			std::cout << "Enter new value: ";
			std::cin >> value6;
			std::cout << "Count: " << list.FindAndChange(value5, value6) << std::endl;
			break;

		case 11:
			list.Reverse();
			std::cout << "Reversed\n";
			break;

		case 0:
			return 0;

		default:
			std::cout << "Unknown option!\n";
			break;
		}
	}
}