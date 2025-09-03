#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Member {
public:
    Member(int id, string name, int months);
    Member();

    void printStatus();
    bool extend(int n);
    void cancel();
    int getId() { return id; }
    string getName() { return name; }
    int getMonths() { return months; }

private:
    int id;
    string name;
    int months;
};

Member::Member() {
    id = 0;
    name = "";
    months = 0;
}

Member::Member(int id, string name, int months) {
    this->id = id;
    this->name = name;

    if (months < 0) {
        this->months = 0; 
    } else {
        this->months = months;
    }
}

void Member::printStatus() {
    cout << "Member " << id << " : " << name
         << ", subscription valid for " << months << " months" << endl;
}

bool Member::extend(int n) {
    if (n <= 0) return false;
    months += n;
    return true;
}

void Member::cancel() {
    months = 0;
}

void PrintAllStatus(Member members[], int size) {
    bool any = false;
    for (int i = 0; i < size; i++) {
        if (members[i].getId() != 0) {
            members[i].printStatus();
            any = true;
        }
    }
    if (!any) {
        cout << "No members in the system" << endl;
    }
    cout << endl;
}

int main() {
    Member members[10];
    string command;

    cout << "|        Please create your account        |" << endl;
    cout << "| Type create/extend/cancel/delete Id Name |" << endl;
    cout << "|           ===== Example =====            |" << endl;
    cout << "|            create 7 John Doe             |" << endl;
    cout << "|           ===================            |" << endl;

    while (true) {
        getline(cin, command);
        if (command == "quit") break;

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "create") {
            int id;
            string fname, lname;
            ss >> id >> fname >> lname;
            string name = fname + " " + lname;

            bool created = false;
            for (int i = 0; i < 10; i++) {
                if (members[i].getId() == 0) {
                    members[i] = Member(id, name, 0);
                    created = true;
                    break;
                }
            }
            if (!created) {
                cout << "Cannot perform this operation" << endl;
            }
            PrintAllStatus(members, 10);
        }

        else if (action == "delete") {
            int id;
            ss >> id;
            bool deleted = false;
            for (int i = 0; i < 10; i++) {
                if (members[i].getId() == id) {
                    members[i] = Member();
                    deleted = true;
                }
            }
            if (!deleted) {
                cout << "Cannot perform this operation" << endl;
            }
            PrintAllStatus(members, 10);
        }

        else if (action == "extend") {
            int id, n;
            ss >> id >> n;
            bool extended = false;
            for (int i = 0; i < 10; i++) {
                if (members[i].getId() == id) {
                    extended = members[i].extend(n);
                    break;
                }
            }
            if (!extended) {
                cout << "Cannot perform this operation" << endl;
            }
            PrintAllStatus(members, 10);
        }

        else if (action == "cancel") {
            int id;
            ss >> id;
            bool cancelled = false;
            for (int i = 0; i < 10; i++) {
                if (members[i].getId() == id) {
                    members[i].cancel();
                    cancelled = true;
                    break;
                }
            }
            if (!cancelled) {
                cout << "Cannot perform this operation" << endl;
            }
            PrintAllStatus(members, 10);
        }
    }
    return 0;
}