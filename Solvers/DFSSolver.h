//
// Created by ASUS on 01-06-2025.
//

#include<bits/stdc++.h>
#include "../Models/AbstractRubiksCube.h"

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

// Typename T: RubiksCube Representation used (3d, 1d, Bitboard)
// Typename H: Corresponding Hash function

template<typename T, typename H>
class DFSSolver {
private:
    vector<AbstractRubiksCube::MOVE> moves;
    int max_search_depth;

    //    DFS code to find the solution (helper function)
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;
        for (int i = 0; i < 18; i++) {
            auto m = static_cast<AbstractRubiksCube::MOVE>(i);
            rubiksCube.move(m);             // Apply move to actual cube
            moves.push_back(m);
            if (dfs(dep + 1)) return true;
            moves.pop_back();
            rubiksCube.invert(static_cast<AbstractRubiksCube::MOVE>(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T _rubiksCube, int _max_search_depth = 8) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    vector<AbstractRubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};

#endif //DFSSOLVER_H
