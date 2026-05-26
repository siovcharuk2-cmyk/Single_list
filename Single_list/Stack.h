#pragma once
#include <iostream>
#include "List.h"

template <class T>
class Stack :
    public List<T>
{
public:
    Stack() : List<T>{}
    { }
    
    void AddToHead(const T& value) override
    {
        List<T>::AddToHead(value);
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

