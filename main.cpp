#include <bits/stdc++.h>
// #include "Models/RubiksCubeBitboardModel.cpp"
#include "Solvers/IDAStarSolver.h"
#include "PatternDatabases/CornerDatabaseMaker.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    // CornerDBMaker Testing --------------------------------------------------------------------------
    string fileName = R"(C:\Users\ASUS\CLionProjects\rubiks-cube-solver\Databases\CornerDatabase.bin)";

    //    Code to create Corner Database
    //    CornerDBMaker dbMaker(fileName, 0x99);
    //    dbMaker.bfsAndStore();
    try {
        RubiksCubeBitboardModel cube;
        auto shuffleMoves = cube.randomShuffle(13);
        cube.print();
        for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
        cout << "\n";

        IDAStarSolver<RubiksCubeBitboardModel, HashBitboard> idaStarSolver(cube, fileName);
        auto moves = idaStarSolver.solve();

        idaStarSolver.rubiksCube.print();
        for (auto move: moves) cout << cube.getMove(move) << " ";
        cout << "\n";

        return 0;
    } catch (const char* errMsg) {
        std::cerr << "Error: " << errMsg << std::endl;
        return 1;
    }

}