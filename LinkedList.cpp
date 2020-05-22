#include"LinkedList.h"
#include<iostream>

template<class LData>
LinkedList<LData>::LinkedList()
{
	numofdata = 0;
	head = new Node();
	tail = new Node();

	head->next = tail;
	head->prev = nullptr;

	tail->prev = head;
	tail->next = nullptr
}

template<class LData>
void LinkedList<LData>::Lpush_front(LData data)
{
	Node* newnode = new Node();
	newnode->next = head;
	newnode->prev = nullptr;
	head->data = data;
	head->next->prev = head;
	head = newnode;
	numofdata++;
}

template<class LData>
void LinkedList<LData>::Lpush_back(LData data)
{
	Node* newnode = new Node();
	newnode->prev = tail;
	newnode->next = nullptr;
	tail->data = data;
	tail->prev->next = tail;
	tail = newnode;
	numofdata++;
}

template<class LData>
void LinkedList<LData>::Lpop_front(LData data)
{
	Node* rnode = head->next;
	rnode->next->prev = head;
	head->next = rnode->next;
	rnode->next = nullptr;
	rnode->prev = nullptr;
	numofdata--;
	delete rnode;
}

template<class LData>
void LinkedList<LData>::Lpop_back(LData data)
{
	Node* rnode = tail->prev;
	rnode->prev->next = tail;
	tail->prev = rnode->prev;
	rnode->next = nullptr;
	rnode->prev = nullptr;
	numofdata--;
	delete rnode;
}

template<class LData>
int LinkedList<LData>::Lsize()
{
	return numofdata;
}

template<class LData>
LData LinkedList::Lfront()
{
	return head->next->data;
}
template<class LData>
LData LinkedList::Lback()
{
	return tail->next->data;
}

template<class LData>
bool LinkedList::Lempty()
{
	if(numofdata == 0)
		return true;
	else return false;
}