#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class MembershipSys {
public:
    MembershipSys(int id, int capacity, int reserved);
    MembershipSys();

    void printStatus();
    bool registerMember(int number);
    bool cancelMember(int number);
    int getId() { return id; };

private:
    int id;
    int capacity;
    int reserved;
};

MembershipSys::MembershipSys() {
    id = 0, capacity = 0, reserved = 0;
}

MembershipSys::MembershipSys(int id, int capacity, int reserved){
    this -> id = id;
    this -> capacity = capacity;

    if(reserved < 0) {
        this -> reserved = 0;
    }

    if (reserved > capacity) {
        this -> reserved = capacity;
    } else {
        this -> reserved = reserved;
    }
}

bool MembershipSys::cancelMember(int number){
    if(number <= 0 || reserved < number){
        return false;
    }
    reserved -= number;

    return true;
}

bool MembershipSys::registerMember(int number){
    if(number <= 0 || reserved + number > capacity){
        return false;
    }
    reserved += number;

    return true;
}

void MembershipSys::printStatus(){
    cout << "Gym " << id << ": " << reserved << "/" << capacity
         << " (" << (100 * reserved / capacity) << "%) members registered" << endl;
}

void PrintAllStatus(MembershipSys registerNums[], int size){
    bool any = false;

    for(int i = 0; i < size; i++){        
        if(registerNums[i].getId() != 0){
            registerNums[i].printStatus();
            any = true;
        }
    }

    if (!any) {
        cout << "=== Id numbers is not in the systems! ===";
    }
    cout << endl;
}

int main () {
    //code

    MembershipSys registerNums[10];

    string command;
    while (true) {
        getline(cin, command);
        if (command == "quit") break;

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "create"){
            int id, cap;
            bool created = false;
            ss >> id >> cap;
            for (int i = 0; i < 10; i++) {
                if(registerNums[i].getId() == 0){
                    registerNums[i] = MembershipSys(id, cap, 0);
                    created = true;
                    break;
                }
                if(!created) {
                    cout << "Your User has been created!" << endl;
                }
                PrintAllStatus(registerNums, 10);
            }
        } 

        else if (action == "delete") {
            int id;
            ss >> id;
            bool deleted = false;
            for (int i = 0; i < 10; i++) {
                if (registerNums[i].getId() == id) {
                    registerNums[i] = MembershipSys();
                    deleted = true;
                }
            }
            if (!deleted) {
                cout << "Cannot perform this operation" << endl;
                PrintAllStatus(registerNums, 10);
            }
        }

        else if (action == "extend") {
            
        }
        
    }
    return 0;
}