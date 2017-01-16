#pragma once
#include<iostream>

using namespace std;

template <class T>
class Stack
{
private:

	int index;
	int capacity;
	T* container;

public:
	Stack(int capacity)
	{
		container = new T[capacity];
		this->capacity = capacity;
		this->index = capacity - 1;
	}

	~Stack()
	{
		delete[] this->container;
	}
	void push(T c)
	{
		this->container[index--] = c;
	}

	void pop()
	{
		this->index++;
	}
	T peak() 
	{
		return container[index + 1];
	}
	bool isEmpty()
	{
		return (this->index == this->capacity - 1) ? true : false;
	}
};