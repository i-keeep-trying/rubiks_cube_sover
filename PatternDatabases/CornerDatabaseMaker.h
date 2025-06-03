//
// Created by ASUS on 02-06-2025.
//

#ifndef CORNERDATABASEMAKER_H
#define CORNERDATABASEMAKER_H

#include "CornerPatternDatabase.h"
#include "../Models/RubiksCubeBitboardModel.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};



#endif //CORNERDATABASEMAKER_H
