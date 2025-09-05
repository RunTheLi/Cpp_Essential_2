#include <iostream>

using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
private:
  int id;
  int capacity;
  int reserved;
};

void FlightBooking::printStatus()
{
  // print report here
  cout << "Flight " << id << ":" << reserved << "/" << capacity << " (" << (100 *reserved / capacity) << "% seats reserved" << endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members
  this -> id = id;
  if(capacity > 0){
    this -> capacity = capacity;
  } else {
    this -> capacity = 0;
  }

  if(reserved > 0){
    this -> reserved = reserved;
  } else {
    this -> reserved = 0;
  }
}

int main() {
  int reserved = 0,
      capacity = 0;
  cout << "Provide flight capacity: ";
  cin >> capacity;

  cout << "Provide number of reserved seats: ";
  cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();

  return 0;
}