#include <iostream>
#include <sstream>
#include <vector>
#include <exception>

using namespace std;

class IpAddress {
    private:
        int a, b, c, d;
    public:
    IpAddress(const string& ipStr);
    void print(int range) const;

};

IpAddress::IpAddress(const string& ipStr) {
    stringstream ss(ipStr);
    char d1, d2, d3;
    
    ss >> a >> d1 >> b >> d2 >> c >> d3 >> d;

    if (ss.fail() || d1 != '.' || d2 != '.' || d3 != '.') {
        throw runtime_error("Exception - invalid IP number.");
    }

    if (a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255) {
            throw runtime_error("Exception - invalid IP number.");
        }

}

void IpAddress::print(int range) const {
    vector<int> valid = {1, 2, 4, 8, 16, 32, 64, 128, 256};
    bool ok = false;

    for (int x : valid) {
        if (range == x) ok = true;
    }

    if(!ok) {
        throw runtime_error("Exception - invalid range.");
    }

    int start = (d / range) * range;

    for (int i = 0; i < range; ++i) {
        int last = start + i;
        if( last > 255) break;

        cout << a << "." << b << "." << c << "." << last << endl;
    }
}

int main () {
    vector<pair<string,int>> testData = {
        {"212.111.212.128", 2},
        {"212.112.212.128", 4},
        {"212.113.212.128", 6},   
        {"212.114.212.328", 4}    
    };

    for (auto &[ipStr, range] : testData) {
        try {
            IpAddress ip(ipStr);       
            ip.print(range);           
        }
        catch (const exception &e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}