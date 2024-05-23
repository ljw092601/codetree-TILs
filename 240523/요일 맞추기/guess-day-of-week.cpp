#include <iostream>
#include <string>
using namespace std;

int main() {
    string weekday[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    string r_weekday[7] = {"Mon", "Sun", "Sat", "Fri", "Thu", "Wed", "Tue"};
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int f_day = 0;
    for (int i=0; i<m1; i++) {
        f_day += num_of_days[i];
    }
    f_day += d1;
    int s_day = 0;
    for (int i=0; i<m2; i++) {
        s_day += num_of_days[i];
    }
    s_day += d2;
    int diff_day = s_day - f_day;
    if (diff_day >= 0) cout << weekday[diff_day % 7];
    else cout << r_weekday[(-diff_day) % 7];
    return 0;
}