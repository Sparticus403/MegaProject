//
//  AVLTree.h
//  MegaProject
//
//  Created by Williamson, Todd on 4/19/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTreeNode.hpp"
#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinarySearchTreeNode<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balanceSubTree(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent, Type value);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);
    
public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};

/*
 A negative value means the right is greater than the left
 */
template <class Type>
int AVLTree<Type> :: heightDifference(BinarySearchTreeNode<Type> * node)
{
    int balance;
    int leftHeight = calculateHeight(node->getLeftChild());
    int rightHeight = calculateHeight(node->getRightChild());
    balance = leftHeight - rightHeight;
    return balance;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild(); //setting the parent to the leftChild
    
    parent->setLeftChild(changedNode->getRightChild()); //sets the parent's child to the changed node's right child
    
    changedNode->setRightChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(changedNode->getLeftChild());
    
    changedNode->setLeftChild(parent);
    
    return changedNode;
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getRightChild();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinarySearchTreeNode<Type> * parent)
{
    BinarySearchTreeNode<Type> * changedNode;
    changedNode = parent->getLeftChild();
    
    parent->setLeftChild(rightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinarySearchTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftChild()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRightChild()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    
    return parent;
}

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template <class Type>
AVLTree<Type> :: ~AVLTree()
{
    delete this->getRoot();
}

//remove node

template <class Type>
BinarySearchTreeNode<Type> * AVLTree<Type> :: insertNode(BinarySearchTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinarySearchTreeNode<Type>(inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getLeftChild(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightChild(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}

#endif /* AVLTree_h */
