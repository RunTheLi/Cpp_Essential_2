#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() { return id; };

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking() {
    id = 0; capacity = 0; reserved = 0;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;

    if (reserved > capacity) {
        this->reserved = capacity;
    }
    else if (reserved < 0) {
        this->reserved = 0;
    }
    else {
        this->reserved = reserved;
    }
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats <= 0 || reserved < number_of_seats) {
        return false;
    }
    reserved -= number_of_seats;
    return true;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (number_of_seats <= 0 || (100 * (reserved + number_of_seats)) > (105 * capacity)) {
        return false;
    }
    reserved += number_of_seats;
    return true;
}

void FlightBooking::printStatus() {
    cout << "Flight " << id << ": " << reserved << "/" << capacity
         << " (" << (100 * reserved / capacity) << "%) seats reserved" << endl;
}

// ---- Helper function to print all flights ----
void printAllFlights(FlightBooking booking[], int size) {
    bool any = false;
    for (int i = 0; i < size; i++) {
        if (booking[i].getId() != 0) {
            booking[i].printStatus();
            any = true;
        }
    }
    if (!any) {
        cout << "No flights in the system" << endl;
    }
    cout << endl; // match expected blank line between states
}

int main() {
    FlightBooking booking[10];

    string command;
    while (true) {
        getline(cin, command);
        if (command == "quit") break;

        stringstream ss(command);
        string action;
        ss >> action;

        if (action == "create") {
            int id, cap;
            ss >> id >> cap;
            bool created = false;
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == 0) {
                    booking[i] = FlightBooking(id, cap, 0);
                    created = true;
                    break;
                }
            }
            if (!created) cout << "Cannot perform this operation" << endl;
            printAllFlights(booking, 10);
        }

        else if (action == "delete") {
            int id;
            ss >> id;
            bool deleted = false;
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    booking[i] = FlightBooking();
                    deleted = true;
                }
            }
            if (!deleted) cout << "Cannot perform this operation" << endl;
            printAllFlights(booking, 10);
        }

        else if (action == "add") {
            int id, n;
            ss >> id >> n;
            bool ok = false;
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    ok = booking[i].reserveSeats(n);
                    break;
                }
            }
            if (!ok) cout << "Cannot perform this operation" << endl;
            printAllFlights(booking, 10);
        }

        else if (action == "cancel") {
            int id, n;
            ss >> id >> n;
            bool ok = false;
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    ok = booking[i].cancelReservations(n);
                    break;
                }
            }
            if (!ok) cout << "Cannot perform this operation" << endl;
            printAllFlights(booking, 10);
        }
    }

    return 0;
}
