#include <iostream>
#include <windows.h>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);


	//List<int> list;

	//while (true)
	//{
	//	short user_choice;

	//	std::cout <<
	//		"======== MENU ========\n" <<
	//		"1. AddToHead\n" <<
	//		"2. AddToTail\n" <<
	//		"3. DeleteFromHead\n" <<
	//		"4. DeleteFromTail\n" <<
	//		"5. DeleteAll\n" <<
	//		"6. Show\n" <<
	//		"7. Insert\n" <<
	//		"8. DeleteAt\n" <<
	//		"9. Find\n" <<
	//		"10. FindAndChange\n" <<
	//		"11. Reverse\n" <<
	//		"0. Exit\n" <<
	//		"> ";
	//	std::cin >> user_choice;

	//	switch (user_choice)
	//	{
	//	case 1:
	//		int value1;
	//		std::cout << "Enter value: ";
	//		std::cin >> value1;
	//		list.AddToHead(value1);
	//		break;

	//	case 2:
	//		int value2;
	//		std::cout << "Enter value: ";
	//		std::cin >> value2;
	//		list.AddToTail(value2);
	//		break;

	//	case 3:
	//		list.DeleteFromHead();
	//		std::cout << "Item deleted\n";
	//		break;

	//	case 4:
	//		list.DeleteFromTail();
	//		std::cout << "Item deleted\n";
	//		break;

	//	case 5:
	//		list.DeleteAll();
	//		std::cout << "Items deleted\n";
	//		break;

	//	case 6:
	//		list.Show();
	//		break;

	//	case 7:
	//		int value3,
	//			index;
	//		std::cout << "Enter value: ";
	//		std::cin >> value3;
	//		std::cout << "Enter index: ";
	//		std::cin >> index;
	//		list.Insert(value3, index);
	//		break;

	//	case 8:
	//		int index2;
	//		std::cout << "Enter index: ";
	//		std::cin >> index2;
	//		list.DeleteAt(index2);
	//		break;

	//	case 9:
	//		int value4;
	//		std::cout << "Enter value: ";
	//		std::cin >> value4;
	//		std::cout << "Index: " << list.Find(value4) << std::endl;
	//		break;

	//	case 10:
	//		int value5,
	//			value6;
	//		std::cout << "Enter value: ";
	//		std::cin >> value5;
	//		std::cout << "Enter new value: ";
	//		std::cin >> value6;
	//		std::cout << "Count: " << list.FindAndChange(value5, value6) << std::endl;
	//		break;

	//	case 11:
	//		list.Reverse();
	//		std::cout << "Reversed\n";
	//		break;

	//	case 0:
	//		return 0;

	//	default:
	//		std::cout << "Unknown option!\n";
	//		break;
	//	}
	//}

	
	//List<int> l1;
	//List<int> l2;
	//List<int> l3;

	//l1.AddToHead(7);
	//l1.AddToHead(6);
	//l1.AddToHead(5);
	//l1.AddToHead(4);

	//l2.AddToHead(4);
	//l2.AddToHead(3);
	//l2.AddToHead(2);
	//l2.AddToHead(1);

	//l3.AddToHead(10);

	//l1.Show();
	//l2.Show();
	//l3.Show();

	//std::cout << "====== 3.clone(1) =======\n";
	//l3.setHead(l1.clone());
	//l3.Show();

	//std::cout << "====== 1 = 3 + 2 =======\n";
	//l1.setHead(l3 + l2);
	//l1.Show();

	//std::cout << "====== 3 = 1 * 2 =======\n";
	//l3.setHead(l1* l2);
	//l3.Show();



	std::cout << "====== Stack ======\n";
	List<int>* ListPtr;
	ListPtr = new Stack<int>{};

	std::cout << "Порожній стек: ";
	ListPtr->Show();
	
	std::cout << "Додав 1, 4, 7, 9\n";
	ListPtr->AddToHead(1);
	ListPtr->AddToHead(4);
	ListPtr->AddToHead(7);
	ListPtr->AddToHead(9);
	ListPtr->Show();

	std::cout << "Видалив 2 елемента\n";
	ListPtr->DeleteFromHead();
	ListPtr->DeleteFromHead();
	ListPtr->Show();
	delete ListPtr;

	std::cout << "\n\n====== Queue ======\n";
	ListPtr = new Queue<int>{};

	std::cout << "Порожня черга: ";
	ListPtr->Show();

	std::cout << "Додав 1, 4, 7, 9\n";
	ListPtr->AddToTail(1);
	ListPtr->AddToTail(4);
	ListPtr->AddToTail(7);
	ListPtr->AddToTail(9);
	ListPtr->Show();

	std::cout << "Видалив 2 елемента\n";
	ListPtr->DeleteFromHead();
	ListPtr->DeleteFromHead();
	ListPtr->Show();
	delete ListPtr;
}