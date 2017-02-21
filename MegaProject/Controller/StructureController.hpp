//
//  StructureController.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef StructureController_hpp
#define StructureController_hpp

#include "../Model/Array.hpp"
#include "../Model/Node.hpp"
#include <string>
using namespace std;

class StructureController
{
private:
    Node<int> numberNode;
    Node<string> wordNode;
    Array<int> numberArray;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();
public:
    StructureController();
    void start();
};

#endif /* StructureController_hpp */
