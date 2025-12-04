#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class InvalidTowerException : public runtime_error {
    public:
    InvalidTowerException(const string& msg) : runtime_error(msg) {}
};

class IllegalMoveException : public runtime_error {
    public:
    IllegalMoveException(const string& msg) : runtime_error(msg) {}
};

class EmptyTowerException : public runtime_error {
    public:
    EmptyTowerException(const string& msg) : runtime_error(msg) {}
};

class TowerOfHanoi {
    private:
        vector<int> towers[3]; 

    public:
        TowerOfHanoi();

        void move(int from, int to);

        void printTowers() const;
};  

TowerOfHanoi::TowerOfHanoi() {
    towers[0] = {3, 2, 1};  
    towers[1].clear();      
    towers[2].clear();       
}

void TowerOfHanoi::move(int from, int to) {
    if (from < 1 || from > 3 || to < 1 || to > 3)
        throw InvalidTowerException("Tower number must be 1-3.");

    if (towers[from-1].empty())
        throw EmptyTowerException("Source tower is empty.");

    if (!towers[to-1].empty() && towers[from-1].back() > towers[to-1].back())
        throw IllegalMoveException("Cannot place bigger disk on smaller disk.");

    int disk = towers[from-1].back();
    towers[from-1].pop_back();
    towers[to-1].push_back(disk);
}


void TowerOfHanoi::printTowers() const {
    for (int i = 0; i < 3; ++i) {
        cout << "tower_" << (i+1) << ": ";

        if (towers[i].empty()) {
            cout << "empty";
        } else {
            for (int disk : towers[i]) {
                cout << disk << " ";
            }
        }
        cout << endl;
    }
}

int main () {
    TowerOfHanoi game;
    int moveCommand;
    
    while (true) {
        cin >> moveCommand;
        if (moveCommand == 0) break;

        int from = moveCommand / 10;  // tens digit
        int to   = moveCommand % 10;  // ones digit

        if (from == to) continue;

        try {
            game.move(from, to);
        } catch (const InvalidTowerException &e) {
            cout << e.what() << endl;
        } catch (const EmptyTowerException &e) {
            cout << e.what() << endl;
        } catch (const IllegalMoveException &e) {
            cout << e.what() << endl;
        }
    }

    // After all moves, print the final tower state
    game.printTowers();

    return 0;
}
