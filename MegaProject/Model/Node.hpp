//
//  Node.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    Type getNodeData();
    Node<Type> * getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type> * nextPointer);
};
    
    
/*
 Implementation section of the templated class
*/

template <class Type>
Node<Type> :: Node()
{
    nextPointer = nullptr;
    //Explicitly not initializing nodeData
    //Becuase I do not know what Type it is.
}
    
template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type> * nextNode)
{
    this->nodeData = value;
    this->nextPointer = nextNode;
}
template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}
    
template <class Type>
Node<Type> * Node<Type> :: getNextPointer()
{
    return nextPointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type value)
{
    this->nodeData = value;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type> * pointer)
{
    this->nextPointer = pointer;
}
    
#endif /* Node_hpp */
