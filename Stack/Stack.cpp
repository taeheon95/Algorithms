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
