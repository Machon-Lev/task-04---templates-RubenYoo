#include "PriorityQueue.h"

void PriorityQueue::push(const int& t)
{

	MyComparator<int> compare;

	for (auto it = _myData.begin(); it != _myData.end(); it++)
		if (compare.operator()(t, *it) < 0) {
			_myData.insert(it, t);
			return;
		}
	

	_myData.emplace_back(t);
}

int PriorityQueue::poll()
{
	if (_myData.empty())
		throw std::out_of_range("PriorityQueue empty !");

	int lastElement = _myData.front();
	_myData.pop_front();

	return lastElement;
}
