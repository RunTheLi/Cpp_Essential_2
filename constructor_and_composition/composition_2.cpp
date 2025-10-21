#include <iostream>
#include <string>
#include <vector>

using namespace std;

// === Component Classes ===
class Engine {
private:
    string size;
public:
    Engine(string s) : size(s) {}          // constructor
    void print() const {
        cout << "Engine: " << size << endl;
    }
};

class Wheel {
private:
    string size;
public:
    Wheel(string s) : size(s) {}
    void print() const {
        cout << "Wheel: " << size << endl;
    }
};

class Chassis { 
private:
    string size;
public:
    Chassis(string s) : size(s) {}
    void print() const {
        cout << "Chassis: " << size << endl;
    }
};

class Light { 
private:
    string size;
public:
    Light(string s) : size(s) {}
    void print() const {
        cout << "Light: " << size << endl;
    }
};

class Body { 
private:
    string size;
public:
    Body(string s) : size(s) {}
    void print() const {
        cout << "Body: " << size << endl;
    }
};

// === Car Class ===
#include <vector>

// === Car Class ===
class Car {
private:
    Engine engine;
    vector<Wheel> wheels;
    Chassis chassis;
    vector<Light> lights;
    Body body;
public:
    Car() : engine("1.0"), chassis("Normal"), body("Black") {
    for (int i = 0; i < 4; i++) {
            wheels.push_back(Wheel("16inches"));
        }
        for (int i = 0; i < 10; i++) {
            int type = (i / 2) + 1;
            lights.push_back(Light("Type " + to_string(type)));
        }
    }

    // Print method
    void print() const {
        engine.print();
        for (const auto &w : wheels) w.print();
        chassis.print();
        for (const auto &l : lights) l.print();
        body.print();
    }
};



// === Main ===
int main() {
    Car myCar;
    myCar.print();
    return 0;
}
