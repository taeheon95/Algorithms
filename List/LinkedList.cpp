#include"LinkedList.h"
#include<iostream>

template<class Type>
LinkedList<Type>::LinkedList()
{
	numofdata = 0;
	head = new Node();
	tail = new Node();

	head->next = tail;
	head->prev = nullptr;

	tail->prev = head;
	tail->next = nullptr
}

template<class Type>
void LinkedList<Type>::Lpush_front(Type data)
{
	Node* newnode = new Node();
	newnode->next = head;
	newnode->prev = nullptr;
	head->data = data;
	head->next->prev = head;
	head = newnode;
	numofdata++;
}

template<class Type>
void LinkedList<Type>::Lpush_back(Type data)
{
	Node* newnode = new Node();
	newnode->prev = tail;
	newnode->next = nullptr;
	tail->data = data;
	tail->prev->next = tail;
	tail = newnode;
	numofdata++;
}

template<class Type>
int LinkedList<Type>::Lpop_front()
{
	if(numofdata>0){
		Node* rnode = head->next;
		rnode->next->prev = head;
		head->next = rnode->next;
		rnode->next = nullptr;
		rnode->prev = nullptr;
		numofdata--;
		delete rnode;
		return 1;
	}
	else
	{
		return -1;
	}
	
}

template<class Type>
int LinkedList<Type>::Lpop_back()
{
	if(numofdata>0){
		Node* rnode = tail->prev;
		rnode->prev->next = tail;
		tail->prev = rnode->prev;
		rnode->next = nullptr;
		rnode->prev = nullptr;
		numofdata--;
		delete rnode;
		return 1;
	}
	else
	{
		return -1;
	}
}

template<class Type>
int LinkedList<Type>::Lsize()
{
	return numofdata;
}

template<class Type>
Type LinkedList<Type>::Lfront()
{
	return head->next->data;
}
template<class Type>
Type LinkedList<Type>::Lback()
{
	return tail->prev->data;
}

template<class Type>
bool LinkedList<Type>::Lempty()
{
	if(numofdata == 0)
		return true;
	else return false;
}

template<class Type>
void LinkedList<Type>::Linsert(Type data, int index=0)
{
	if(index == 0)
		this.Lpush_front(data);
	else if (index == numofdata)
		this.Lpush_back(data);
	else if (index < numofdata){
		Node* cur = head->next;
		Node* newnode = new Node();
		newnode->data = data;
		for(int i=0; i<index; i++)
			cur = cur->next;
		newnode->prev = cur;
		newnode->next = cur->next;
		cur->next->prev = newnode;
		cur->next = newnode;
	}
	numofdata++;
}

template<class Type>
void LinkedList<Type>::Lerase(int index)
{
	if(index == 0)
		this.Lpop_front();
	else if(index == numofdata)
		this.Lpop_back();
	else if(index < numofdata){
		Node* cur = head->next;
		Node* rnode;
		for(int i=0; i<index; i++)
			cur = cur->next;
		rnode = cur->next;
		cur->next = rnode->next;
		rnode->next->prev = cur;
		rnode->prev = nullptr;
		rnode->next = nullptr;
		delete rnode;
	}
	numofdata--;
}