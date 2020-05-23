#pragma once

template<class LData>
class Node {
public:
	LData data;
	Node* next;
	Node* prev;
	Node() 
	{ 
		data = 0; 
		next = nullptr;
		prev = nullptr; 
	}
};

template<class LData>
class LinkedList
{
private:
	int numofdata;
	Node* head;
	Node* tail;
public:
	LinkedList();
	void Lpush_front(LData data);
	void Lpush_back(LData data);
	int Lpop_front();
	int Lpop_back();
	int Lsize();
	LData Lfront();
	LData Lback();
	bool Lempty();
	void Linsert(int index, LData data);
	void Lerase(int index);
};