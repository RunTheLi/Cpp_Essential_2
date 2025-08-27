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
        ShopItemOrder(string name, double price, int qty){
            item_name = name;
            unit_price = price;
            quantity = qty;
        }
  // Write your code here
    string get_name() {
        return item_name;
    } 
    double get_price() {
        return unit_price;
    }
    int get_quantity() {
        return quantity;
    }
    
    void set_name(string name) {
         item_name = name; 
        }
    void set_unit_price(double price) {
         unit_price = price; 
        }
    void set_quantity(int qty) {
         quantity = qty; 
        }

    double get_total_price(){
        return unit_price * quantity;
    }

    void print() {
        cout << "Order: " << quantity << " x " << item_name
             << " @ " << unit_price << " each"
             << " | Total = " << get_total_price() << endl;
    }
};

int main(){
    ShopItemOrder order("Apple", 1.5, 10);
    order.print();

    return 0;
}