#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int range = max(c/a, c/b) + 1;
    int max_sum = 0;
    for (int i=0; i<range; i++) {
        for (int p=0; p<range; p++) {
            int sum = 0;
            if (a * i + b * p <= c) sum = a * i + b * p;
            if (max_sum < sum) max_sum = sum;
        }
    }
    cout << max_sum;
    return 0;
}