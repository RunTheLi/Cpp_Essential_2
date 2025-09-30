#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Piece {
protected:
    pair<int,int> parsePosition(string pos) {
        int col = pos[0] - 'a' + 1;
        int row = pos[1] - '0';
        return {col, row};
    }

public:
    virtual bool checkMove(string from, string to) = 0;
    virtual ~Piece() {}
};

class Man : public Piece {
public:
bool checkMove(string from, string to) override {
    pair<int,int> fromCoord = parsePosition(from);
    pair<int,int> toCoord = parsePosition(to);

    int deltaRow = toCoord.second - fromCoord.second;
    int deltaCol = toCoord.first - fromCoord.first;

        if (deltaRow == 1 && abs(deltaCol == 1)) {
            return true;
        } else {
            return false;
        }
    }
};

class King : public Piece {
public:
bool checkMove(string from, string to) override {
    pair<int,int> fromCoord = parsePosition(from);
    pair<int,int> toCoord = parsePosition(to);

    int deltaRow = toCoord.second - fromCoord.second;
    int deltaCol = toCoord.first - fromCoord.first;

        if (abs(deltaRow) == abs(deltaCol)) {
            return true;
        } else {
            return false;
        }   
    }
};


int main () {
    Piece* piece;

    piece = new (Man);
    cout << boolalpha << piece->checkMove("b1", "c2") << endl; 
    delete piece;

    piece = new (King);
    cout << boolalpha << piece->checkMove("b1", "d3") << endl; 
    delete piece;
    
    piece = new (Man);
    cout << boolalpha << piece->checkMove("b1", "d3") << endl; 
    delete piece;

    return 0;
}

