#ifndef _VECTOR_BASED_STACK_CLASS_H_
#define _VECTOR_BASED_STACK_CLASS_H_

#include <vector>        // vector class used by object composition
#include "Exception.h"   // for UnderflowError exception

//using namespace std;

template <typename T>
class Stack
{
    public:
        // constructor. create an empty stack
        Stack();

        // push (insert) item onto the stack.
        // Postcondition: the stack has a new topmost element and
        // the stack size increases by 1
        void push(const T& item);

        // remove the item from the top of the stack.
        // Precondition: the stack is not empty.
        // if the stack is empty, the function throws
        // the UnderflowError exception
        void pop();
     
        // return a reference to the element on the top
        // of the stack.
        // Precondition: the stack is not empty.
        // if the stack is empty, the function throws
        // the UnderflowError exception
        T& top();

        // constant version of top()
        const T& top() const;

        // determine whether the stack is empty
        bool empty() const;

        // return the number of elements in the stack
        int size() const;

    private:
        // a vector object maintains the stack items and size
        vector<T> stackVector;
};

// the constructor has nothing to do. the default
// constructor for the vector class initializes
// stackVector to be empty
template <typename T>
Stack<T>::Stack()
{}

// push item on the stack by inserting it at
// the rear of the vector
template <typename T>
void Stack<T>::push(const T& item)
{
    stackVector.push_back(item);
}

// pop the stack by removing the item at
// the rear of the vector
template <typename T>
void Stack<T>::pop()
{
    // check for an empty stack
    if (empty())
        throw UnderflowError("Stack pop(): stack empty");

    // pop the stack
    stackVector.pop_back();
}

// the top of the stack is at the rear of the vector
template <typename T>
T& Stack<T>::top()
{
    // check for an empty stack
    if (empty())
        throw UnderflowError("Stack top(): stack empty");

    // return the element at the rear of the vector
    return stackVector.back();
}
  
// constant version of top()
template <typename T>
const T& Stack<T>::top() const
{
    // check for an empty stack
    if (empty())
        throw UnderflowError("Stack top(): stack empty");

    // return the element at the rear of the vector
    return stackVector.back();
}
  
template <typename T>
bool Stack<T>::empty() const
{
    return stackVector.size() == 0;
}

template <typename T>
int Stack<T>::size() const
{
    return stackVector.size();
}

#endif  // _VECTOR_BASED_STACK_CLASS_H_
