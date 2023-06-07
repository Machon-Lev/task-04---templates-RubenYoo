#pragma once

#include <iostream>
#include <list>
#include <exception>

template <typename T>
struct MyComparator;

// any templates?
class PriorityQueue {
   
public:
	
   // You need to complete the implement : 
	void push(const int& t); 
	int poll();

private:
// add relevant data members
	std::list<int> _myData;
};

template <typename T>
struct MyComparator {
	int operator()(T a, T b) const {
		return a - b;
	}
};
