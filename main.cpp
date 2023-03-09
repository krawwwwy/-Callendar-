#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}


    bool is_valid() {
        if (year < 0 or month < 1 or month > 12 or day < 1 or day > 31)
            return false;
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;
        if (month == 2) {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
                if (day > 29) return false;
            }
            else {
                if (day > 28) return false;
            }
        }
        return true;
    }

    string get_weekday() {
        static string weekday[] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббоат", "Воскрсенье", };
        int y = year, m = month, d = day;
        if (m == 1 or m == 2) {
            m += 12;
            y--;
        }
        int week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        return weekday[week];
    }

    bool is_weekend() {
        if (get_weekday() == "Суббота" or get_weekday() == "Воскресенье") {
            return true;
        }
        if (month == 1 and day == 1) { 
            return true;
        }
        if (month == 5 and day == 1) { 
            return true;
        }
        if (month == 2 and day == 23) { 
            return true;
        }
        if (month == 12 and (day == 25 || day == 26)) { 
            return true;
        }
        if (month == 3 and day == 8) { 
            return true;
        }
        return false;
    }

    int days_in_month() {
        if (month == 4 or month == 6 or month == 9 or month == 11) {
            return 30;
        }
        if (month == 2) {
            if (year % 4 == 0 and year % 100 != 0 or year % 400 == 0) {
                return 29;
            }
            else {
                return 28;
            }
        }
        return 31;
    }

    void print_date() {
        printf("%02d-%02d-%04d", day, month, year);
    }
};
int main() {
    setlocale(LC_ALL, "Russian");
    int y, m, d;
    cout << "Введите год : " << endl;
    cin >> y;
    cout << "Введите месяц(1-12) : " << endl;
    cin >> m;
    cout << "Введите день(1-31) : " << endl;
    cin >> d;
    Date date(y, m, d);
    if (date.is_valid()) {
        cout << "День недели: " << date.get_weekday() << endl;
        cout << "Выходной: " << (date.is_weekend() ? "Да" : "Нет") << endl;
        cout << "Дней в месяце: " << date.days_in_month() << endl;
        cout << "Дата: ";
        date.print_date();
    }
    else {
        cout << "Invalid date" << endl;
    }
    return 0;
}
