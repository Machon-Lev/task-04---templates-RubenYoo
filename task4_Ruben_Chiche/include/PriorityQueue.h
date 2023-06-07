#pragma once

#include <iostream>
#include <list>
#include <exception>

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


struct MyComparator {
	int operator()(int a, int b) const {
		return a - b;
	}
};
