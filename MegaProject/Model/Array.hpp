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

template <class Type>
class Node
{
private:
    Node<Type> * front;
    int size;
public:
    Array<Type>(int size);
    int getSize();
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
};

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
        Node<Type> * currentnode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

template <class Type>
int Array<Type> :: getSize()
{
    return size;
}

Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    Type value;
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer;
    }
    
    value = current->getNodeData();
    
    return value;
}

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

#endif /* Header_h */