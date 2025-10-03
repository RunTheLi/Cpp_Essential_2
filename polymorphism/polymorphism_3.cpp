#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class IPAddress {
protected:
    string ip;
public:
    IPAddress(string ipAddress) {
        ip = ipAddress;
    }

    IPAddress(const IPAddress &other) {
        ip = other.ip;
    }

    virtual void print() {
        cout << ip << endl;
    }

    virtual ~IPAddress() {}
};



class IPAddressCheck : public IPAddress {
private:
    bool isCorrect;
public:
    IPAddressCheck(string ipAddress) : IPAddress(ipAddress) {
        isCorrect = true;

        stringstream ss(ipAddress);
        string segment;
        int count = 0;

        while (getline(ss, segment, '.')) {
            count++;
            int num;
            try {
                num = stoi(segment);
            } catch (...) {
                isCorrect = false;
                break;
            }
            if (num < 0 || num > 255) {
                isCorrect = false;
            }
        }
        if (count != 4) isCorrect = false;
    }

    IPAddressCheck(const IPAddressCheck &other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    void print() override {
        cout << ip;
        if (isCorrect)
            cout << " - Correct" << endl;
        else
            cout << " - Not Correct" << endl;
    }
};

int main() {
    IPAddress ip1("1.2.3.4");
    IPAddressCheck ip2("999.29.29.29");
    IPAddressCheck ip3("199.29.29.29");

    IPAddress* arr[3];  
    arr[0] = &ip1;
    arr[1] = &ip2;
    arr[2] = &ip3;

    for (int i = 0; i < 3; i++) {
        arr[i]->print();  
    }

    return 0;
}