/*ให้นักเรียนได้ฝึก:

เขียน operator ที่สามารถ “แก้ไขข้อมูลภายในคลาส” ได้

เขียน iostream operators (<<, >>)

ทำความเข้าใจ “การใช้ operator ในรูปแบบที่ไม่ธรรมชาติ” เพื่อให้คิดถึงความเหมาะสมของการ overload operator

สถานการณ์ (Scenario)

ให้เขียน คลาสคอนเทนเนอร์อย่างง่าย (simple container class) ที่ใช้เก็บข้อมูลของ stack
(ชนิดข้อมูลที่เก็บจะเป็นอะไรก็ได้ เช่น int, double ฯลฯ)

พื้นฐานของ stack

Stack คือโครงสร้างข้อมูลที่มีการทำงาน 2 แบบหลัก:

push → เพิ่มข้อมูลเข้าไปใน stack

pop → เอาข้อมูลที่อยู่บนสุดของ stack ออก (ตัวที่ถูกเพิ่มล่าสุด)

ลักษณะของ stack คือ LIFO (Last In, First Out) — คือใส่หลังสุดออกก่อน*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
private:
    std::vector<int> data;

    public:
    Stack () {  }

    void push(int value);
    int pop();
    int top();

    friend ostream& operator<<(ostream& out, Stack& s);
    friend istream& operator>>(istream& in, Stack& s);
};

void Stack::push(int value) {
    data.push_back(value);
}

int Stack::pop() {
    if (data.empty()) {
        throw runtime_error("Exception: stack is empty.");
    }
    int topValue = data.back();
    data.pop_back();             
    return topValue;
}

int Stack::top(){
    if(data.empty()) {
        throw runtime_error("Exception: stack is empty.");
    }
    return data.back();
}

ostream& operator<<(ostream& out, Stack& s) {
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    s.push(value);         
    return out;
}

istream& operator>>(istream& in, Stack& s) {
    try {
        int value = s.pop();
        cout << value << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    return in;
}


int main() {
    Stack s;
    int n;

    cout << "How many items to push? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << s;
    }

    cout << "How many items to pop? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
    }
    
    return 0;
}

/*#include <iostream>
#include <stdexcept>

using namespace std;

struct stackElement {
    double value;
    stackElement* prev;
};

class Stack {
public:
    Stack() : p(nullptr) {}

    void push(const double& rhs) {
        stackElement* t = new stackElement;
        t->value = rhs;
        t->prev = p;
        p = t;
    }

    void printPop(ostream& os) {
        if (p == nullptr) {
            throw runtime_error("stack is empty.");
        }
        double value = top();
        stackElement* t = p->prev;
        os << value << endl;
        delete p;
        p = t;
    }

private:
    double top() const {
        return p->value;
    }
    stackElement* p;
};

istream& operator>>(istream& is, Stack& rhs) {
    double value;
    is >> value;
    rhs.push(value);
    return is;
}

ostream& operator<<(ostream& os, Stack& rhs) {
    try {
        rhs.printPop(os);
    } catch (const exception& ex) {
        os << "Exception: " << ex.what() << endl;
    }
    return os;
}

int main() {
    Stack stack;
    unsigned count;
    cin >> count;
    for (unsigned i = 0; i < count; i++) {
        cin >> stack;
    }

    cin >> count;
    for (unsigned i = 0; i < count; i++) {
        cout << stack;
    }

    return 0;
} */
