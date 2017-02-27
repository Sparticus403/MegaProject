//
//  BiDirectionalNode.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/27/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    Type data;
    BiDirectionalNode<Type> * next;
    BiDirectionalNode<Type> * previous;
public:
    //Constructors
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
    
    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPoiner(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node()
{
    
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
{
    
}

#endif /* BiDirectionalNode_h */
