// This File specifies the basic operation on a stack as a linked list
#ifndef STACK_H
#define STACK_H

template<class Type>
class node
{
    public:
        Type data;
        node<Type> *next;
        node(Type data)
        {
            this.data = data;
            this.next = nullptr;
        }
        node()
        {
            this.data = NULL;
            this.next = nullptr;
        }
};

template<class Type>
class Stack
{
    private:
        node<Type> *stackTop;
        int size;
    public:
        void display();
        Stack();
        ~Stack();
        bool isEmpty();
        void push(Type item);
        Type top();
        void pop();
        void clear();
};

#endif