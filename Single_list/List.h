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
};