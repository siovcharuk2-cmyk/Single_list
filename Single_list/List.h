#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class List
{
private:
	Node<T>* head;

public:
	List() : head{ nullptr }
	{ }

	~List()
	{
		DeleteAll();
	}

	void AddToHead(const T& value)
	{
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->next = head;
		head = nodePtr;
	}

	void DeleteFromHead()
	{
		if (head != nullptr)
		{
			Node<T>* nodePtr = head;
			head = head->next;
			delete nodePtr;
		}
	}

	void AddToTail(const T& value)
	{
		if (head == nullptr) {
			AddToHead(value);
			return;
		}

		Node<T>* nodePtr = new Node<T>(value);
		Node<T>* lastNodePtr = head;
		while (lastNodePtr->next != nullptr)
			lastNodePtr = lastNodePtr->next;

		lastNodePtr->next = nodePtr;
	}

	void DeleteFromTail()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}

		Node<T>* preLastNodePtr = head;
		while (preLastNodePtr->next->next != nullptr)
			preLastNodePtr = preLastNodePtr->next;

		delete preLastNodePtr->next;
		preLastNodePtr->next = nullptr;
	}

	void DeleteAll()
	{
		while (head != nullptr)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void Show() const
	{
		for (Node<T>* nodePtr = head;
			nodePtr != nullptr;
			nodePtr = nodePtr->next)
		{
			std::cout << nodePtr->value << ' ';
		}
		std::cout << '\n';
	}

	void Insert(const T& value, int index)
	{
		if (index < 0) return;

		if (index == 0)
		{
			AddToHead(value);
			return;
		}

		Node<T>* current = head;
		for (int i = 0; i < index - 1 && current != nullptr; ++i)
			current = current->next;

		if (current == nullptr) return;

		Node<T>* newNode = new Node<T>(value);
		newNode->next = current->next;
		current->next = newNode;

	}

	void DeleteAt(int index)
	{
		if (head == nullptr || index < 0) return;

		if (index == 0)
		{
			DeleteFromHead();
			return;
		}

		Node<T>* current = head;
		for (int i = 0; i < index - 1 && current->next != nullptr; ++i)
			current = current->next;

		if (current->next == nullptr) return;

		Node<T>* nodeToDelete = current->next;
		current->next = nodeToDelete->next;
		delete nodeToDelete;
	}

	int Find(const T& valueFind)
	{
		if (head == nullptr) return NULL;

		bool found = false;
		int index = 0;
		for (Node<T>* current = head;
			current != nullptr;
			current = current->next)
		{
			if (current->value == valueFind)
			{
				found = true;
				break;
			}
			index++;
		}

		if (found) return index;
		else return NULL;
	}

	int FindAndChange(const T& valueFind, const T& newValue)
	{
		if (head == nullptr) return -1;

		bool found = false;
		int count = 0;
		for (Node<T>* current = head;
			current != nullptr;
			current = current->next)
		{
			if (current->value == valueFind)
			{
				found = true;
				current->value = newValue;
				count++;
			}
		}

		if (found) return count;
		else return -1;
	}

	void Reverse()
	{
		if (head == nullptr || head->next == nullptr) return;

		Node<T>* prev = nullptr;
		Node<T>* current = head;
		Node<T>* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}
};