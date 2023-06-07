#include "PriorityQueue.h"

void PriorityQueue::push(const int& t)
{

}

int PriorityQueue::poll()
{
	if (_myData.empty())
		throw std::out_of_range("PriorityQueue empty !");

	int lastElement = _myData.front();
	_myData.pop_front();

	return lastElement;
}
