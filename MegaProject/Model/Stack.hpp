//
//  Stack.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 3/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : DoublyLinkedList<Type>
{
private:
public:
    Stack();
    ~Stack();
    
    void add(Type value);
    Type remove(int index);
    
    Type pop();
    Type peek();
    void push(Type data);
};

template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
Stack<Type> :: ~Stack()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() !=nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}

/*
The add method only adds to the end on a stack. Never at an index
 Implemented only to avoid abstract status in this class.
*/
template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}
/*
 1. Creates a new node
 2. If the stack is empty sets front to the new node
 3. Else sets the end's next to point to the new node and the new nodes previous to end
 4. Move end to the new node.
 5. Increases the size by 1.
*/

template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode<Type>(addedThing);
    
    if(this->size == 0 || this->getFront == nullptr || this->getEnd == nullptr)
    {
        this->setFront(addToStack);
    }
    else
    {
        this->end->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}


template <class Type>
Type Stack<Type> :: remove(int index)
{
    assert(index == this->getSize() - 1 && this->getSize() > 0);
    return pop();
}

template <class Type>
Type Stack<Type> :: peek()
{
    assert(this->getSize() > 0);
    return this->end->getNodeData();
}

/*
 1. Assert size > 0.
 2. Get data from end node.
 3. Move end to ends previous
 4. Delete old end node.
 5. Decrease size.
 6. Return data from old end.
*/
template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    
    delete this->getEnd();
    
    this->setEnd(update);
    
    return removed;
}
#endif /* Stack_h */
