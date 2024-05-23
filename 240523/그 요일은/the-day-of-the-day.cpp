#include <iostream>
#include <string>
using namespace std;

int week_to_int(string week) {
    if (week == "Mon") return 0;
    if (week == "Tue") return 1;
    if (week == "Wed") return 2;
    if (week == "Thu") return 3;
    if (week == "Fri") return 4;
    if (week == "Sat") return 5;
    if (week == "Sun") return 6;
}

int main() {
    int num_of_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    string week;
    cin >> week;
    int weekday = week_to_int(week);
    int f_day = 0;
    for (int i=0; i<m1; i++) {
        f_day += num_of_days[i];
    }
    f_day += d1;
    f_day += weekday;
    int s_day = 0;
    for (int i=0; i<m2; i++) {
        s_day += num_of_days[i];
    }
    s_day += d2;
    int diff_day = s_day - f_day;
    cout << ((diff_day >= 0) ? diff_day / 7 + 1 : 0);
    return 0;
}