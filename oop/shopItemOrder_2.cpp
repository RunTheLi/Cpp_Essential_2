#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ShopItemOrder
{
    private:
        string item_name;
        double unit_price;
        int quantity;

    public:
        ShopItemOrder() {
            item_name = "";
            unit_price = 0.0;
            quantity = 0;
        }

        // Method to read input
        void read() {
            cout << "Please Enter Item Name: ";
            cin >> item_name;
            cout << "Please Enter Item Price: ";
            cin >> unit_price;
            cout << "Please Enter Item Quantity: ";
            cin >> quantity;
        }

    double get_total_price() {
        return unit_price * quantity;
    }

    void print() {
        cout << "Order: " << quantity << " x " << item_name
             << " @ " << unit_price << " each"
             << " | Total = " << get_total_price() << endl;
    }
};

int main (){
    ShopItemOrder order;
    order.read();
    order.print();

    return 0;
}