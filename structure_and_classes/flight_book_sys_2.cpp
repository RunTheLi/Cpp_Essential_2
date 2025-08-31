#include <iostream>
#include <string>

using namespace std;

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
private:
  int id;
  int capacity;
  int reserved;
};
// ...
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  // Save data to members according to limits
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

  if((100 * this -> reserved) > (105 * this -> capacity)){
    this->reserved = (105 * this->capacity) / 100;
  }
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
  // try to add reservations and return 'true' on success
  // keep the limits in mind
  if(number_ob_seats <= 0 || (100 * (reserved + number_ob_seats)) > (105 * capacity)) {
    return false;
  }
    reserved += number_ob_seats;

  return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    // try to cancel reservations and return 'true' on success
  // keep the limits in mind
    if (number_of_seats <= 0 || reserved < number_of_seats) {
        return false;
    }
    reserved -= number_of_seats;
    return true;
}

void FlightBooking::printStatus() {
    if (capacity > 0) {
        cout << "Flight " << id << ": " << reserved << "/" << capacity
             << " (" << (100 * reserved / capacity) << "%) seats reserved" << endl;
    } else {
        cout << "Flight " << id << ": capacity is 0 (invalid)" << endl;
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

  string command = "";
  cin.ignore();
  while (command != "quit")
  {
    booking.printStatus();
    cout << "What would you like to do?: ";
    getline(std::cin, command);

    // handle the command
  if (command == "quit") {
            break; // ออกจากโปรแกรม
        }
        else if (command.rfind("add ", 0) == 0) {
            int n = stoi(command.substr(4));
            if (booking.reserveSeats(n))
                cout << "Seats reserved successfully!\n";
            else
                cout << "Cannot perform this operation\n";
        }
        else if (command.rfind("cancel ", 0) == 0) {
            int n = stoi(command.substr(7));
            if (booking.cancelReservations(n))
                cout << "Seats cancelled successfully!\n";
            else
                cout << "Cannot perform this operation\n";
        }
        else {
            cout << "Cannot perform this operation\n";
        }
    }

    cout << "Program terminated.\n";
    return 0;
}