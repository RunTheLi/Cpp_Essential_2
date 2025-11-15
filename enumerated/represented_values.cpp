#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Calendar {
private:
    int day;
    int month;
    int year;
    int daycount;

public:
    // ==== Constructor ====
    Calendar(int day, int month, int year)
        : day(day), month(month), year(year)
    {

        int maxDay;
        switch(month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                maxDay = 31; break;
            case 4: case 6: case 9: case 11:
                maxDay = 30; break;
            case 2:
                maxDay = isLeapYear(year) ? 29 : 28; break;
            }

        if (day < 1 || day > maxDay)
            throw invalid_argument("Invalid day for this month/year");

        if (year < 1970)
            throw invalid_argument("Year must be >= 1970");

        if (month < 1 || month > 12)
            throw invalid_argument("Invalid Month");
        
        daycount = calculateDayCount();
    }

    // ==== Leap Year ====
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // ==== Calculate Day Count ====
    int calculateDayCount() {
        static const int monthDays[13] = {
            0, // dummy
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        int total = 0;

        // 1. Add full years from 1970 to previous year
        for (int y = 1970; y < year; y++) {
            total += isLeapYear(y) ? 366 : 365;
        }

        // 2. Add days of full months before this month
        for (int m = 1; m < month; m++) {
            if (m == 2 && isLeapYear(year)) {
                total += 29;
            } else {
                total += monthDays[m];
            }
        }

        // 3. Add days of current month
        total += day;

        return total - 1;  // because 1 Jan 1970 = daycount 0
    }

    // ==== Print ====
    void print() {
        static const string monthNames[13] = {
            "", "January","February","March","April","May","June",
            "July","August","September","October","November","December"
        };

        static const string weekNames[7] = {
            "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"
        };

        int base = 4; // Friday for 1 Jan 1970
        int weekdayIndex = (base + (daycount % 7)) % 7;

        cout << day << " "
             << monthNames[month] << " "
             << year << " - "
             << weekNames[weekdayIndex] << " - "
             << daycount
             << " days since 1st January 1970." << endl;
    }
};

int main() {
    int d, m, y;

    cout << "Enter day month year: " << endl;
    cin >> d >> m >> y;

    try {
        Calendar c(d, m ,y);
        c.print();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
