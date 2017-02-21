//
//  Array.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include <assert.h>
#include "Node.hpp"
#include <iostream>

using namespace std;

template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
public:
    Array<Type>();
    Array<Type>(int size);
    
    //Destructor
    ~Array<Type>();
    //copy Constructor
    Array<Type>(const Array<Type> & toBeCopied);
    //Assignment Operator overload
    void operator = (const Array<Type> & toBeAssigned);
    
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};

template <class Type>
Array<Type> :: Array()
{
    
}
/*
 Creates an Array of specified size by linking Node<Type> together.
 */
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * currentNode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    current->setNodeData(value);
}

template <class Type>
Node<Type> * Array<Type> :: getFront() const
{
    return front;
}

template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //move to next node in array
        front = front->getNodePointer();
        cout << "Moving to the next node. At: " << count << endl;
        //Delete the front pointer
        delete remove;
        cout << "Deleting the old front pointer." << endl;
        //move delete to the new front
        remove = front;
        cout << "Moving to new front pointer." << endl;
        count--;
        cout << "Front is at: " << front << " count is: " << count << endl;
    }
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //Build Data Structure
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNodePointer(front);
        front = temp;
    }
    
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNodePointer();
        copyTemp = copyTemp->getNodePointer();
    }
}

#endif /* Header_h */
