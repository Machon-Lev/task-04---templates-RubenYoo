#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
struct MyComparator;

// A template priority queue class
template <typename T>
class PriorityQueue {
   
public:
	// methods
	void push(const T& t); 
	T poll();

private:
	std::list<T> _myData;
};


// A struct to compare two object
template <typename T>
struct MyComparator {
	T operator()(T a, T b) const {
		return a - b;
	}
};

// putting the T object in the right place
template <typename T>
void PriorityQueue<T>::push(const T& t)
{

	MyComparator<T> compare;

	for (auto it = _myData.begin(); it != _myData.end(); it++)
		if (compare.operator()(t, *it) < 0) {
			_myData.insert(it, t);
			return;
		}

	_myData.emplace_back(t);
}

// extract the first object of the list (the min object)
template <typename T>
T PriorityQueue<T>::poll()
{
	if (_myData.empty())
		throw std::out_of_range("PriorityQueue empty !");

	T lastElement = _myData.front();
	_myData.pop_front();

	return lastElement;
}
