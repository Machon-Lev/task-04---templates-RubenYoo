#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
struct MyComparator;


template <typename T>
class PriorityQueue {
   
public:
	
	void push(const T& t); 
	T poll();

private:
	std::list<int> _myData;
};

template <typename T>
struct MyComparator {
	int operator()(T a, T b) const {
		return a - b;
	}
};

template <typename T>
void PriorityQueue<T>::push(const T& t)
{

	MyComparator<int> compare;

	for (auto it = _myData.begin(); it != _myData.end(); it++)
		if (compare.operator()(t, *it) < 0) {
			_myData.insert(it, t);
			return;
		}

	_myData.emplace_back(t);
}

template <typename T>
T PriorityQueue<T>::poll()
{
	if (_myData.empty())
		throw std::out_of_range("PriorityQueue empty !");

	T lastElement = _myData.front();
	_myData.pop_front();

	return lastElement;
}
