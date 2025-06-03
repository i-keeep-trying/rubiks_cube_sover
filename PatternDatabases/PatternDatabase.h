//
// Created by ASUS on 02-06-2025.
//

#ifndef PATTERNDATABASE_H
#define PATTERNDATABASE_H

#include "../Models/AbstractRubiksCube.h"
#include "NibbleArray.h"
#include "bits/stdc++.h"

using namespace std;

class PatternDatabase {

    NibbleArray database;
    size_t size;
    size_t numItems;

    PatternDatabase();

public:
    PatternDatabase(size_t size);
    //    Testing for init_val
    PatternDatabase(size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const AbstractRubiksCube &cube) const = 0;

    virtual bool setNumMoves(const AbstractRubiksCube &cube, uint8_t numMoves);

    virtual bool setNumMoves(uint32_t ind, uint8_t numMoves);

    virtual uint8_t getNumMoves(const AbstractRubiksCube &cube) const;

    virtual uint8_t getNumMoves(uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();
};



#endif //PATTERNDATABASE_H
