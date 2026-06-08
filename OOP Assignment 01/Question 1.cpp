#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 0;
        month = 0;
        year = 0;
    }

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    void showDate() {
        cout << day << "/" << month << "/" << year << endl;
    }

    int getYear() {
        return year;
    }

    bool isLeapYear(int y) {
        if (y % 4 == 0) {
            return true;
        }
        else {
            return false;
        }       
    }

    bool isValid(int d, int m, int y) {
        if (y < 1 || m < 1 || m > 12 || d < 1 || d > 31) {
            return false;
        }
            
        int daysInMonth = 0;

        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            daysInMonth = 31;
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            daysInMonth = 30;

        }
        else if (m == 2) {
            if (isLeapYear(y)) {
                daysInMonth = 29;
            } 
            else {
                daysInMonth = 28;
            }
        }

        if (d > daysInMonth) {
            return false;
        }
        return true;
    }

    void calculateAge(Date current) {
   
        if ((year > current.year) ||
            (year == current.year && month > current.month) ||
            (year == current.year && month == current.month && day > current.day)) {

            cout << endl << "Error: Birth date must be before current date." << endl;
            return;
        }

        int d = current.day;
        int m = current.month;
        int y = current.year;

        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

        if (isLeapYear(y)) {
            daysInMonth[1] = 29;
        }
        else {
            daysInMonth[1] = 28;
        }

        if (d < day) {
            m--;
            if (m == 0) {
                m = 12;
                y--;
            }

            if (isLeapYear(y)) {
                daysInMonth[1] = 29;

            }
            else {
                daysInMonth[1] = 28;

                d += daysInMonth[m - 1];
            }
               
        }

        if (m < month) {
            m += 12;
            y--;
        }

        int diffDay = d - day;
        int diffMonth = m - month;
        int diffYear = y - year;

        cout << "Your Age: " << diffYear << " years, "
            << diffMonth << " months, and "
            << diffDay << " days." << endl;
    }
};

int main() {
    int d1, m1, y1;
    int d2, m2, y2;

    cout << "Enter Birth Date (DD MM YYYY): ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter Current Date (DD MM YYYY): ";
    cin >> d2 >> m2 >> y2;

    Date birth, current;

    bool isBirthValid = birth.isValid(d1, m1, y1);
    bool isCurrentValid = current.isValid(d2, m2, y2);

    if (isBirthValid && isCurrentValid) {
        birth.setDate(d1, m1, y1);
        current.setDate(d2, m2, y2);

        cout << "Birth Date: ";
        birth.showDate();
        cout << "Current Date: ";
        current.showDate();

        cout << "(Checking using getter: Birth Year = " << birth.getYear() << ")" << endl;

        birth.calculateAge(current);
    }
    else {
        cout << "Error: One or both entered dates are invalid. Age cannot be calculated." << endl;
    }

    return 0;
}
