#include <iostream>
using namespace std;

int main() {
    int num_of_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1,d1,m2,d2;
    cin >> m1 >> d1 >> m2 >> d2;
    int day = 0;
    for (int i = m1+1; i != m2; i++) {
        day += num_of_days[i];
    }
    day += num_of_days[m1] - d1 + 1;
    day += d2;
    cout << day;
    return 0;
}