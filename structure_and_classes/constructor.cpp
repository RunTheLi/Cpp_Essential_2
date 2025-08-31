class Class {
public:
    Class(void) { this -> value = -1; }
        void setVal(int value) { this -> value = value; }
    int getVal(void) { return value; }
private:
        int value;
};