#include <iostream>
using namespace std;

class Piece {
    protected:
        string from;
    public:
        Piece(const string& start) : from(start) {}
        virtual ~Piece() {}

        virtual bool canMove(string& to) 
            const = 0;

        const string& startSquare() const { return from; }
    };

class Man : public Piece {
    public:
    // Man:canMoveRo using the man rule
};

class King : public Piece {
    public:
    // King:canMoveRo using the man rule
};

int main () {
    return 0;
}