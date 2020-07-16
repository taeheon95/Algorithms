#ifndef __LinkedList_h__
#define __LinkedList_h__

template<class Type>
class Node {
public:
	Type data;
	Node* next;
	Node* prev;
	Node() 
	{ 
		data = 0; 
		next = nullptr;
		prev = nullptr; 
	}
};

template<class Type>
class LinkedList
{
private:
	int numofdata;
	Node* head;
	Node* tail;
public:
	LinkedList();
	void Lpush_front(Type data);
	void Lpush_back(Type data);
	int Lpop_front();
	int Lpop_back();
	int Lsize();
	Type Lfront();
	Type Lback();
	bool Lempty();
	void Linsert(int index, Type data);
	void Lerase(int index);
};

#endif