//
// Created by ASUS on 30-05-2025.
//

#include "AbstractRubiksCube.h"

class RubiksCube1DArrayModel : public AbstractRubiksCube {
    public:
    char cube[54]{};
    //initialises cube
    RubiksCube1DArrayModel() {
        for (int i = 0; i < 54; i+=9) {
            for (int j = 0; j < 9; j++) {
                cube[i + j] = getColorLetter(static_cast<COLOR>(i/9));
            }
        }
    };

    //returns the index in the 1D array given the row and index
    static int getIdx(FACE face, uint8_t row, uint8_t col) {
        return ((static_cast<int>(face))*9 + row*3 + col);
    }

    //returns the color given the letter
    static COLOR getLetterColor(char letter) {
        switch (letter) {
            case 'G':
                return COLOR::GREEN;
            case 'R':
                return COLOR::RED;
            case 'B':
                return COLOR::BLUE;
            case 'O':
                return COLOR::ORANGE;
            case 'Y':
                return COLOR::YELLOW;
            default:
                return COLOR::WHITE;
        }
    }

    //returns the color given the face, row and column
    [[nodiscard]] COLOR getColor(const FACE face, const uint8_t row, const uint8_t col) const override {
        return (getLetterColor(cube[getIdx(face, row, col)]));
    }

    //checks if it is solved
    [[nodiscard]] bool isSolved() const override {
        bool solved = true;
        for (int i = 0; i < 54; i+=9) {
            for (int j = 0; j < 9; j++) {
                if (static_cast<COLOR>(i/9) != getLetterColor(cube[i+j])) {
                    solved = false;
                    break;
                }
            }
        }
        return solved;
    };

    //rotates the face clockwise
    void rotateFaceClockwise(FACE face) {
        int st = static_cast<int>(face)*9;
        char temp[9]{};
        for (int i=st; i<st+9; i++) {
            temp[i-st] = cube[i];
        }
        for (int i=0; i<3; i++) {
            cube[st+(i+1)*3-1] = temp[i];
            cube[st+(i+1)*3-2] = temp[i+3];
            cube[st+(i+1)*3-3] = temp[i+6];
        }
    }

    //rotates the face counter-clockwise
    void rotateFaceCounterClockwise(FACE face) {
        const int st = static_cast<int>(face)*9;
        char temp[9]{};
        for (int i=st; i<st+9; i++) {
            temp[i-st] = cube[i];
        }
        for (int i=0; i<3; i++) {
            cube[st+i] = temp[(i+1)*3-1];
            cube[st+i+3] = temp[(i+1)*3-2];
            cube[st+i+6] = temp[(i+1)*3-3];
        }
    }

    //implementing all possible 18 moves
    AbstractRubiksCube &u() override {
        rotateFaceClockwise(FACE::UP);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, 0, i)];
            cube[getIdx(FACE::FRONT, 0, i)] = cube[getIdx(FACE::RIGHT, 0, i)];
            cube[getIdx(FACE::RIGHT, 0, i)] = cube[getIdx(FACE::BACK, 0, i)];
            cube[getIdx(FACE::BACK, 0, i)] = cube[getIdx(FACE::LEFT, 0, i)];
            cube[getIdx(FACE::LEFT, 0, i)] = temp;
        }

        return *this;
    };

    AbstractRubiksCube &u2() override {
        this->u();
        this->u();
        return *this;
    };

    AbstractRubiksCube &uPrime() override {
        rotateFaceCounterClockwise(FACE::UP);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, 0, i)];
            cube[getIdx(FACE::FRONT, 0, i)] = cube[getIdx(FACE::LEFT, 0, i)];
            cube[getIdx(FACE::LEFT, 0, i)] = cube[getIdx(FACE::BACK, 0, i)];
            cube[getIdx(FACE::BACK, 0, i)] = cube[getIdx(FACE::RIGHT, 0, i)];
            cube[getIdx(FACE::RIGHT, 0, i)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &l() override {
        rotateFaceClockwise(FACE::LEFT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, i, 0)];
            cube[getIdx(FACE::FRONT, i, 0)] = cube[getIdx(FACE::UP, i, 0)];
            cube[getIdx(FACE::UP, i, 0)] = cube[getIdx(FACE::BACK, 2-i, 2)];
            cube[getIdx(FACE::BACK, 2-i, 2)] = cube[getIdx(FACE::DOWN, i, 0)];
            cube[getIdx(FACE::DOWN, i, 0)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &lPrime() override {
        rotateFaceCounterClockwise(FACE::LEFT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, i, 0)];
            cube[getIdx(FACE::FRONT, i, 0)] = cube[getIdx(FACE::DOWN, i, 0)];
            cube[getIdx(FACE::DOWN, i, 0)] = cube[getIdx(FACE::BACK, 2-i, 2)];
            cube[getIdx(FACE::BACK, 2-i, 2)] = cube[getIdx(FACE::UP, i, 0)];
            cube[getIdx(FACE::UP, i, 0)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &r() override {
        rotateFaceClockwise(FACE::RIGHT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, i, 2)];
            cube[getIdx(FACE::FRONT, i, 2)] = cube[getIdx(FACE::UP, i, 2)];
            cube[getIdx(FACE::UP, i, 2)] = cube[getIdx(FACE::BACK, 2-i, 0)];
            cube[getIdx(FACE::BACK, 2-i, 0)] = cube[getIdx(FACE::DOWN, i, 2)];
            cube[getIdx(FACE::DOWN, i, 2)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &rPrime() override {
        rotateFaceCounterClockwise(FACE::RIGHT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, i, 2)];
            cube[getIdx(FACE::FRONT, i, 2)] = cube[getIdx(FACE::DOWN, i, 2)];
            cube[getIdx(FACE::DOWN, i, 2)] = cube[getIdx(FACE::BACK, 2-i, 0)];
            cube[getIdx(FACE::BACK, 2-i, 0)] = cube[getIdx(FACE::UP, i, 2)];
            cube[getIdx(FACE::UP, i, 2)] = temp;

        }
        return *this;
    };

    AbstractRubiksCube &d() override {
        rotateFaceClockwise(FACE::DOWN);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, 2, i)];
            cube[getIdx(FACE::FRONT, 2, i)] = cube[getIdx(FACE::LEFT, 2, i)];
            cube[getIdx(FACE::LEFT, 2, i)] = cube[getIdx(FACE::BACK, 2, i)];
            cube[getIdx(FACE::BACK, 2, i)] = cube[getIdx(FACE::RIGHT, 2, i)];
            cube[getIdx(FACE::RIGHT, 2, i)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    };

    AbstractRubiksCube &dPrime() override {
        rotateFaceCounterClockwise(FACE::DOWN);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::FRONT, 2, i)];
            cube[getIdx(FACE::FRONT, 2, i)] = cube[getIdx(FACE::RIGHT, 2, i)];
            cube[getIdx(FACE::RIGHT, 2, i)] = cube[getIdx(FACE::BACK, 2, i)];
            cube[getIdx(FACE::BACK, 2, i)] = cube[getIdx(FACE::LEFT, 2, i)];
            cube[getIdx(FACE::LEFT, 2, i)] = temp;
        }
        return *this;
    };

    AbstractRubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    };

    AbstractRubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    };

    AbstractRubiksCube &f() override {
        rotateFaceClockwise(FACE::FRONT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::UP, 2, i)];
            cube[getIdx(FACE::UP, 2, i)] = cube[getIdx(FACE::LEFT, 2-i, 2)];
            cube[getIdx(FACE::LEFT, 2-i, 2)] = cube[getIdx(FACE::DOWN, 0, 2-i)];
            cube[getIdx(FACE::DOWN, 0, 2-i)] = cube[getIdx(FACE::RIGHT, i, 0)];
            cube[getIdx(FACE::RIGHT, i, 0)] = temp;
        }

        return *this;
    };

    AbstractRubiksCube &fPrime() override {
        rotateFaceCounterClockwise(FACE::FRONT);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::UP, 2, i)];
            cube[getIdx(FACE::UP, 2, i)] = cube[getIdx(FACE::RIGHT, i, 0)];
            cube[getIdx(FACE::RIGHT, i, 0)] = cube[getIdx(FACE::DOWN, 0, 2-i)];
            cube[getIdx(FACE::DOWN, 0, 2-i)] = cube[getIdx(FACE::LEFT, 2-i, 2)];
            cube[getIdx(FACE::LEFT, 2-i, 2)] = temp;
        }

        return *this;
    };

    AbstractRubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    };

    AbstractRubiksCube &b() override {
        rotateFaceClockwise(FACE::BACK);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::UP, 0, i)];
            cube[getIdx(FACE::UP, 0, i)] = cube[getIdx(FACE::RIGHT, i, 2)];
            cube[getIdx(FACE::RIGHT, i, 2)] = cube[getIdx(FACE::DOWN, 2, 2-i)];
            cube[getIdx(FACE::DOWN, 2, 2-i)] = cube[getIdx(FACE::LEFT, 2-i, 0)];
            cube[getIdx(FACE::LEFT, 2-i, 0)] = temp;
        }

        return *this;
    };

    AbstractRubiksCube &bPrime() override {
        rotateFaceCounterClockwise(FACE::BACK);
        for (int i=0; i<3; i++) {
            const char temp = cube[getIdx(FACE::UP, 0, i)];
            cube[getIdx(FACE::UP, 0, i)] = cube[getIdx(FACE::LEFT, 2-i, 0)];
            cube[getIdx(FACE::LEFT, 2-i, 0)] = cube[getIdx(FACE::DOWN, 2, 2-i)];
            cube[getIdx(FACE::DOWN, 2, 2-i)] = cube[getIdx(FACE::RIGHT, i, 2)];
            cube[getIdx(FACE::RIGHT, i, 2)] = temp;
        }

        return *this;
    }

    AbstractRubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    };

    bool operator==(const RubiksCube1DArrayModel &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    RubiksCube1DArrayModel &operator=(const RubiksCube1DArrayModel &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
};

struct Hash1d {
    size_t operator()(const RubiksCube1DArrayModel &r1) const {
        string str = "";
        for (int i = 0; i < 54; i++) str += r1.cube[i];
        return hash<string>()(str);
    }
};