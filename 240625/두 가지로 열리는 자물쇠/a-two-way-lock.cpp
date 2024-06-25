#include <iostream>
#include <cmath>
using namespace std;

bool is_range_2(int a, int b, int n) {
    return (abs(a - b) <= 2 || abs(a - b) >= (n - 2));
}

bool is_open(int correct_a, int correct_b, int correct_c, int a, int b, int c, int n) {
    return (is_range_2(correct_a, a, n) && is_range_2(correct_b, b, n) && is_range_2(correct_c, c, n));
}

int main() {
    int n;
    cin >> n;
    int a1, b1, c1, a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    int open_num = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if(is_open(a1, b1, c1, i, j, k, n) || is_open(a2, b2, c2, i, j, k, n)) open_num++;
            }
        }
    }
    cout << open_num;
    return 0;
}