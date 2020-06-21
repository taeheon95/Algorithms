#include<iostream>
#include"Stack.h"

using namespace std;

template<class Type>
Stack<Type>::Stack()
{
    stackTop = nullptr;
    size = 0;
}
template<class Type>
Stack<Type>::~Stack()
{
    if(isEmpty());
    else{
        node<Type> *delnode = stackTop;
        while(delnode->next != nullptr){
            stackTop = stackTop->next;
            delete delnode;
            delnode = stackTop;
        }
        delete delnode;
    }
}

template<class Type>
void Stack<Type>::display()
{
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    else{
        for(auto i=this->stackTop; i.next != nullptr; i=stackTop.next)
            cout<<i->data<<endl;
    }
    cout<<endl;
    cout<<"Size of stack: "<<size<<endl;
}

template<class Type>
bool Stack<Type>::isEmpty()
{
    return (stackTop == NULL);
}

template<class Type>
void Stack<Type>::push(Type item)
{
    node<Type> *newNode;
    newNode = new node<Type>;
    newNode->data = item;
    newNode->next = stackTop;
    stackTop = newNode;
    size++;
}

template<class Type>
Type Stack<Type>::top()
{
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    else return stackTop->data;
}

template <class Type>
void Stack<Type>::pop()
{
    node<Type> *temp;
    if(!isEmpty()) {
        temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
        size--;
    } else {
        cout << "Stack is empty !" << endl;
    }
}

template <class Type>
Stack<Type> Stack<Type>::operator=(Stack<Type> & otherStack)
{
    node<Type> *newNode, *current, *last;

    if (stackTop != NULL) 
        stackTop = NULL;
    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else {
        current = otherStack.stackTop;
        stackTop = new node<Type>;
        stackTop->data = current->data;
        stackTop->next = NULL;
        last = stackTop;
        current = current ->next;
        while (current != NULL)
        {
            newNode = new node<Type>;
            newNode->data = current->data;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
            current = current->next;
        }
    }
    size = otherStack.size;
    return *this;
}
