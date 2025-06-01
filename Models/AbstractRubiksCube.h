//
// Created by ASUS on 29-05-2025.
//

#ifndef ABSTRACTRUBIKSCUBE_H
#define ABSTRACTRUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

//base class for all Rubiks cube model

class AbstractRubiksCube {
    public:
    virtual ~AbstractRubiksCube() = default;

    //Listing all the faces
    enum class FACE {
        UP, LEFT, FRONT, RIGHT, BACK, DOWN
    };

    // Listing all the possible moves
    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // Listing all the possible colors
    enum class COLOR {
        WHITE, GREEN, RED, BLUE, ORANGE, YELLOW
    };

    // Boolean function to check if the cube is solved or not
    virtual bool isSolved() const = 0;

    // Function to get the color
    virtual  COLOR getColor(FACE face, uint8_t row, uint8_t col) const = 0;

    // Function to get the first letter of the color
    static char getColorLetter(COLOR color);

    //Function to get the move in string format
    static string getMove(MOVE m);

    // Function to print the cube in planar format
    void print() const;

    // Function to randomly shuffle a cube "times" time and return the vector of moves used to shuffle it.
    vector<MOVE> randomShuffle(unsigned int times);

    // Function to perform the move on the cube
    AbstractRubiksCube &move(MOVE m);

    // Function to invert a move
    AbstractRubiksCube &invert(MOVE m);

    // The following functions perform the various rotational moves.
    virtual AbstractRubiksCube &f() = 0;

    virtual AbstractRubiksCube &fPrime() = 0;

    virtual AbstractRubiksCube &f2() = 0;

    virtual AbstractRubiksCube &u() = 0;

    virtual AbstractRubiksCube &uPrime() = 0;

    virtual AbstractRubiksCube &u2() = 0;

    virtual AbstractRubiksCube &l() = 0;

    virtual AbstractRubiksCube &lPrime() = 0;

    virtual AbstractRubiksCube &l2() = 0;

    virtual AbstractRubiksCube &r() = 0;

    virtual AbstractRubiksCube &d() = 0;

    virtual AbstractRubiksCube &dPrime() = 0;

    virtual AbstractRubiksCube &d2() = 0;

    virtual AbstractRubiksCube &rPrime() = 0;

    virtual AbstractRubiksCube &r2() = 0;

    virtual AbstractRubiksCube &b() = 0;

    virtual AbstractRubiksCube &bPrime() = 0;

    virtual AbstractRubiksCube &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};



#endif //ABSTRACTRUBIKSCUBE_H
