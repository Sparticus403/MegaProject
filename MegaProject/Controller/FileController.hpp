//
//  FileController.hpp
//  MegaProject
//
//  Created by Williamson, Todd on 3/29/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Model/DoubleList.hpp"
#include "../Model/Meme.hpp"
//#include "../Model/CrimeData.hpp"
#include <string> //String type
#include <fstream> //file operations
#include <iostream> //console access
#include <sstream> //String as stream

using namespace std; //keyword support

class FileController
{
private:
    DoubleList<Meme> memeList;
public:
    DoubleList<Meme> readMemeDataFromFileAsList(string filename);
    void writeMemeDataStatistics(DoubleList<int> source, string filename);
};

#endif /* FileController_hpp */
