#include <bits/stdc++.h>
#include "RubiksCubeBitboardModel.cpp"
// #include "RubiksCube1DArrayModel.cpp"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    RubiksCubeBitboard r;
    r.print();
    r.u();
    r.l();
    r.f2();
    r.bPrime();
    r.print();
    return 0;
}