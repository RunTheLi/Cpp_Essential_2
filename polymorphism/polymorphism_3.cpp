#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class IPAdress {
    private:
        string value;
    public:
        IPAddress(string ip);
        IPAddress(const IPAddress &other);
        
        void print();
};

class IPAddressChecked : public IPAdress {
    private:
        bool isCorrect;
    public:

};

int main () {

    return 0;
}