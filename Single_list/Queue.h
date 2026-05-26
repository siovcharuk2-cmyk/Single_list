#pragma once
#include <iostream>
#include "List.h"

template <class T>
class Queue :
    public List<T>
{
public:
    Queue() : List<T>()
    { }

    void AddToTail(const T& value) override
    {
        List<T>::AddToTail(value);
        std::cout << "Елемент додано\n";
    }

    void DeleteFromHead() override
    {
        List<T>::DeleteFromHead();
        std::cout << "Елемент видалено\n";
    }

    void Show() const override
    {
        std::cout << "Елементи  ---->  ";
        List<T>::Show();
    }
};

