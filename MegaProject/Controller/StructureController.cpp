//
//  StructureController.cpp
//  MegaProject
//
//  Created by Williamson, Todd on 2/8/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "StructureController.hpp"
#include <iostream>
#include "IntNodeArray.hpp"
#include "../Model/Timer.hpp"
#include "../Model/List.hpp"
#include "../Model/DoubleList.hpp"

using namespace std;

StructureController :: StructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
   // numberArray = Array<int>(1);
}

void StructureController :: testArrayTemplate()
{
    cout << "Array Template" << endl;
    Timer arrayTimer;
    arrayTimer.startTimer();
    //int test [9];
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    arrayTimer.resetTimer();
    arrayTimer.startTimer();
    //numberArray = Array<int>(9);
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    
}

void StructureController :: testNodeTypes()
{
    cout << "Here is a string node" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is an uninitialized int node" << endl;
    cout << numberNode.getNodeData() << endl;
}

void StructureController :: testIntArray()
{
    cout << "Creating an IntNodeArray" << endl;
    IntNodeArray temp = IntNodeArray(3);
    for(int spot = 0; spot < 3; spot++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
    
    for(int spot = 0; spot < 3; spot++)
    {
        temp.setAtIndex(spot, spot);
    }
    for(int spot = 0; spot < temp.getSize(); spot++)
    {
        cout << temp.getFromIndex(spot) << " is at " << spot << endl;
    }
}

void StructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
}

void StructureController :: start()
{
    cout << "Going to test the IntNodeArray" << endl;
    testIntArray();
    cout << "Finished IntNodeArray testing." << endl;
    testListIntro();
}

void StructureController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "int the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should mathch:" << endl;
    cout << words.getFromIndex(0) << " should be the same as" << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "Changed the contents of the copied Array");
}

void StructureController :: testListTiming()
{
    DoubleList<int> timingList;
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds" << endl;
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds" << endl;
    cout << "A time savings of: " << averageSlow - averageFast << " microseconds." << endl;
}

void StructureController :: testMemeQueue()
{
    Meme firstMeme("toddler fist! with pinwheel");
    Meme datMeme("dat boi");
    Meme oneMeme("we are number one");
    
    Queue<Meme> memeQueue;
    memeQueue.add(firstMeme);
    Meme secondMeme;
    secondMeme.setDankness(8435);
    memeQueue.enqueue(secondMeme);
    memeQueue.add(datMeme);
    memeQueue.enqueue(oneMeme);
    oneMeme.setMainstream(false);
    
    Meme temp = memeQueue.dequeue();
    cout << "This should be 8435 and is: " << temp.getDankness() << endl;
    
    cout << "This meme is " << oneMeme.getTitle() << ", and has a dankness level of " << oneMeme.getDankness() << ", and should be 8700" << endl;
    
    cout << "This meme is " << datMeme.getTitle() <<", and has a dankness level of " << datMeme.getDankness() << ", and should be 7500" << endl;
    
}

void StructureController :: testNumberStack()
{
    int firstNumb = 1;
    int secondNumb = 2;
    int thirdNumb = 4;
    Stack<int> numberStack;
    
    numberStack.add(firstNumb);
    
    numberStack.push(secondNumb);
    
    numberStack.push(thirdNumb);
    
    cout << "The top number is: " << numberStack.peek() << endl;
    
    numberStack.pop();
    
    cout << "Now the top number is: " << numberStack.peek() << endl;
    
    numberStack.remove(firstNumb);
    
    /*
    getSize
     */
    
    
}
