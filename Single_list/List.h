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

	void setHead(Node<T>* newHead)
	{
		head = newHead;
	}

	virtual void AddToHead(const T& value)
	{
		Node<T>* nodePtr = new Node<T>(value);
		nodePtr->next = head;
		head = nodePtr;
	}

	virtual void DeleteFromHead()
	{
		if (head != nullptr)
		{
			Node<T>* nodePtr = head;
			head = head->next;
			delete nodePtr;
		}
	}

	virtual void AddToTail(const T& value)
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

	virtual void Show() const
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

	Node<T>* clone() const
	{
		if (head == nullptr) return nullptr;

		Node<T>* newHead = new Node<T>(head->value);
		Node<T>* newCurrent = newHead;
		Node<T>* oldCurrent = head->next;

		while (oldCurrent != nullptr)
		{
			newCurrent->next = new Node<T>(oldCurrent->value);
			newCurrent = newCurrent->next;
			oldCurrent = oldCurrent->next;
		}

		return newHead;
	}

	Node<T>* operator+(const List<T>& other)
	{
		Node<T>* newHead = this->clone();
		Node<T>* otherCloneHead = other.clone();

		if (newHead == nullptr)
			return otherCloneHead;

		Node<T>* current = newHead;
		while (current->next != nullptr)
			current = current->next;

		current->next = otherCloneHead;

		return newHead;
	}

	Node<T>* operator*(const List<T>& other)
	{
		List<T>* newList = new List<T>;

		for (Node<T>* firstPtr = head;
			firstPtr != nullptr;
			firstPtr = firstPtr->next)
		{
			if (newList->Find(firstPtr->value) != NULL)
				continue;
			
			for (Node<T>* secondPtr = other.head;
				secondPtr != nullptr;
				secondPtr = secondPtr->next)
			{
				if (firstPtr->value == secondPtr->value)
				{
					newList->AddToHead(firstPtr->value);
					break;
				}
			}
		}

		newList->Reverse();

		Node<T>* resultHead = newList->head;
		newList->head = nullptr;

		delete newList;

		return resultHead;
	}
};