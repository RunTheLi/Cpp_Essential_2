#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Ipaddress
class IPAddress {
private:
    string address;
public:
    IPAddress(string addr);
    string getAddress() const;
};

IPAddress::IPAddress(string addr) {
    address = addr;
}

string IPAddress::getAddress() const {
    return address;
}

//Network
class Network {
    private:
        vector<IPAddress> addresses;
    public:
        void add(const IPAddress &ip);
        void print() const;
};  

void Network::add(const IPAddress &ip) {
    addresses.push_back(ip);
}

void Network::print() const {
    for(const auto &ip : addresses) {
        cout << ip.getAddress() << endl;
    }
}

int main() {

    IPAddress ip1("1.1.1.1");
    IPAddress ip2("2.2.2.2");
    IPAddress ip3("3.3.3.3");
    IPAddress ip4("4.4.4.4");
    IPAddress ip5("5.5.5.5");

    Network net1;
    Network net2;

    net1.add(ip1);
    net1.add(ip2);
    net1.add(ip3);

    net2.add(ip3);  // shared IP
    net2.add(ip4);
    net2.add(ip5);

    cout << "Network 1:" << endl;
    net1.print();

    cout << "Network 2:" << endl;
    net2.print();
    return 0;
}