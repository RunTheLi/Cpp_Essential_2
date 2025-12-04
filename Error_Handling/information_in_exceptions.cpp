#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IpHeader {
private:
    string sourceIp;
    string destIp;

    bool isValidIp(const string& ip) const;

public:
    IpHeader(const string& src, const string& dst);
    void printStatus() const;
};


bool IpHeader::isValidIp(const string& ip) const {
    stringstream ss(ip);
    int a, b, c, d;
    char d1, d2, d3;

    ss >> a >> d1 >> b >> d2 >> c >> d3 >> d;

    if (ss.fail() || d1 != '.' || d2 != '.' || d3 != '.')
        return false;

    if (a < 0 || a > 255) return false;
    if (b < 0 || b > 255) return false;
    if (c < 0 || c > 255) return false;
    if (d < 0 || d > 255) return false;

    return true;
}

IpHeader::IpHeader(const string& src, const string& dst) {
    sourceIp = src;
    destIp = dst;

    if (!isValidIp(sourceIp)) {
        throw runtime_error("Invalid IP Header - Source IP Address is invalid.");
    }

    if (!isValidIp(destIp)) {
        throw runtime_error("Invalid IP Header - Destination IP Address is invalid.");
    }
}

void IpHeader::printStatus() const {
    cout << "Valid IP Header." << endl;
}

int main() {
    try {
        IpHeader header1("212.112.212.11", "212.112.212.12");
        header1.printStatus();
    } catch (const exception& e) {
        cout << e.what() << endl;
    } 

    try {
        IpHeader header2("212.112.212.333", "212.112.212.33");
        header2.printStatus();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return  0;
}