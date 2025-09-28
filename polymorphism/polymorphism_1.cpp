#include <iostream>
using namespace std;

class Number {
public:
    virtual void draw() {  // virtual method
        cout << "Base Drawing" << endl;
    }
    virtual ~Number() {} // virtual destructor (good practice)
};

class Structure_1 : public Number {
public:
    void draw() override {
        cout << "Drawing 1:" << endl;
        cout << " /\\\n";
        cout << "//\\\\\n";
    }
};

class Structure_2 : public Number {
public:
    void draw() override {
        cout << "Drawing 2:" << endl;
        cout << " / \\\n";
        cout << "/**\\\n";
    }
};

class Structure_3 : public Number {
public:
    void draw() override {
        cout << "Drawing 3:" << endl;
        cout << " / \\\n";
        cout << "/++\\\n";
    }
};

int main() {
    Number* trees[3];   // array of 3 pointers to base class

    trees[0] = new Structure_1();
    trees[1] = new Structure_2();
    trees[2] = new Structure_3();

    for (int i = 0; i < 3; i++) {
        trees[i]->draw();   // polymorphic call
    }

    // cleanup
    for (int i = 0; i < 3; i++) {
        delete trees[i];
    }

    return 0;
}
