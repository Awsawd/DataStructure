//Queue.h
#include <iostream>
#include "list.h"

using namespace std;

template<class T>
class Queue
{
	List<T> queueL;
public:
	Queue(){}
	~Queue() {}
	int Size()const { return (queueL.Size()); }
	bool Empty()const { return queueL.Empty(); }
	const T& Front()const { return queueL.Front(); }
	void Push(const T& item) { queueL.Push_back(item); }
	T Pop() { T item = queueL.Front(); queueL.Pop_front(); return item; }
	void Clear() { queueL.Clear(); }
};
		
