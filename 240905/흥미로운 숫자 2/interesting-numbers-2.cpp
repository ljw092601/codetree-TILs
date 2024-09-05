#include <iostream>
#include <vector>
using namespace std;

vector<int> all_digit(int n) {
    vector<int> digits;
    while(n > 0) {
        digits.emplace_back(n%10);
        n /= 10;
    }
    return digits;
}

bool is_interest(int n) {
    vector<int> digit_vec = all_digit(n);
    int zero_to_nine [10] = {0,};
    for(int d : digit_vec) {
        zero_to_nine[d]++;
    }
    int num_one = 0;
    int num_nonzero = 0;
    for(int n : zero_to_nine) {
        if(n != 0) num_nonzero++;
        if(n == 1) num_one++;
    }
    if (num_one == 1 && num_nonzero == 2) return true;
    else return false;
}

int main() {
    int x, y;
    cin >> x >> y;
    int num = 0;
    for (int i=x; i<=y; i++) {
        if(is_interest(i)) num++;
    }
    cout << num;
    return 0;
}