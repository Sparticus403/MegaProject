//
//  IntNode.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/6/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nextPointer;
public:
    //Methods
    int getNodeData();
    IntNode * getNextPointer();
    void setNodeData(int value);
    void setNextPointer(IntNode * updatedNode);
    
    //Constructors
    IntNode();
    IntNode(int value);
    /*
     Creates an IntNode with a specified value and reference to the next node.
     */
    IntNode(int value, IntNode * nextNode);
    
};

#endif /* IntNode_hpp */
