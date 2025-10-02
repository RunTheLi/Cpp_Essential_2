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

    void print() {
    cout << ip << endl;
}
};


class IPAddressCheck : public IPAddress {
private:
    bool isCorrect;
public:
    IPAddressCheck(string IPAddress) : IPAddress(IPAddress) {
        isCorrect = true;

    stringstream ss(IPAddress);
    string segment;
    int count 0;

    IPAddressCheck(const IPAddressCheck &other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    void print() {
    IPAddress::print();
    if (isCorrect)
        cout << " - Correct" << endl;
    else
        cout << " - Not Correct" << endl;
}
    }
    

};




int main () {
    
    return 0;
}