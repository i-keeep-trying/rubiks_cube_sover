//
// Created by ASUS on 02-06-2025.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H

#include "../Models/AbstractRubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef AbstractRubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const AbstractRubiksCube& cube) const;

};

#endif //CORNERPATTERNDATABASE_H
