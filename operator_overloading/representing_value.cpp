//representing value and value order 
//inite-state machine
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class State { Start = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5, Stop = 6 };

class FSM {
    private:
        vector<State> history;

        State current;
        void transition(int value);
    
    public:
        FSM();
        FSM& operator<<(int value);
        bool isStop() const;

        friend ostream& operator<<(ostream& os, const FSM& fsm);
};

FSM::FSM(){
    current = State::Start;
    history.push_back(State::Start);
}

FSM& FSM::operator<<(int value){
        transition(value);
        return *this;
}

void FSM::transition(int value) {
    if (current == State::Stop) return; // ถ้า Stop แล้ว ไม่ต้องทำอะไร

    if (current == State::Start) {
        current = (value < 5) ? State::S3 : State::S5;
    } else if (current == State::S3) {
        current = State::S4; // ไม่ขึ้นกับ value เพื่อให้ไป S4 ต่อ
    } else if (current == State::S4 || current == State::S5) {
        current = State::Stop;
    }

    history.push_back(current);
}
bool FSM::isStop() const{
    return current == State::Stop;
}

string stateToString(State s) {
    switch(s){
        case State::Start: return "Start";
        case State::S2: return "S2";
        case State::S3: return "S3";
        case State::S4: return "S4";
        case State::S5: return "S5";
        case State::Stop: return "Stop";
    }
    return "";
}

ostream& operator<<(ostream& os, const FSM& fsm) {
    if(fsm.current == State::Stop) {
        os << "Stop state reached\n";
    }
    os << "States visited:\n";

    for (size_t i = 0; i < fsm.history.size(); i++) {
        State s = fsm.history[i];
        os << static_cast<int>(s);

        if (s == State::Start || s == State::Stop) {
            os << "(" << stateToString(s) << ")";
        }

        if ( i != fsm.history.size() - 1) os << ", ";
    }
    
    return os;
}

int main() {
    FSM f;

    f << 3 << 6 << 4; 

    cout << f << endl; 
    return 0;
}

