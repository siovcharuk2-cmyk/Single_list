#pragma once
#include <iostream>

template <typename T>
class Node
{
public:
	T value;
	Node* next;

	Node(const T& value)
		: value{ value },
		next{ nullptr }
	{ }
};

