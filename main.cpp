#include <bits/stdc++.h>
#include "Models/RubiksCubeBitboardModel.cpp"
#include "Solvers/IDDFSSolver.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    RubiksCubeBitboardModel r;
    r.print();
    r.u();
    r.l();
    r.f2();
    r.bPrime();
    r.u2();
    r.dPrime();
    r.r2();
    r.print();
    IDDFSSolver<RubiksCubeBitboardModel, HashBitboard> solver(r, 9);
    vector<AbstractRubiksCube::MOVE> solution = solver.solve();
    for (auto move : solution) {
        cout<<AbstractRubiksCube::getMove(move)<<" ";
    }
    cout<<"\n";
    return 0;
}