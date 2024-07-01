#include <iostream>
#include <vector>
using namespace std;

int get_strike(int correct, int guess) {
    int correct_a = correct / 100;
    int correct_b = (correct / 10) % 10;
    int correct_c = correct % 10;
    int guess_a = guess / 100;
    int guess_b = (guess / 10) % 10;
    int guess_c = guess % 10;
    int strike = 0;
    if (correct_a == guess_a) strike++;
    if (correct_b == guess_b) strike++;
    if (correct_c == guess_c) strike++;
    return strike;
}

int get_ball(int correct, int guess) {
    int correct_a = correct / 100;
    int correct_b = (correct / 10) % 10;
    int correct_c = correct % 10;
    int guess_a = guess / 100;
    int guess_b = (guess / 10) % 10;
    int guess_c = guess % 10;
    int ball = 0;
    if (correct_a == guess_b || correct_a == guess_c) ball++;
    if (correct_b == guess_a || correct_b == guess_c) ball++;
    if (correct_c == guess_a || correct_c == guess_b) ball++;
    return ball;
}

int main() {
    int n;
    cin >> n;
    vector<int> all_num_vec;
    for (int i=1; i<10; i++) {
        for (int p=1; p<10; p++) {
            for (int k=1; k<10; k++) {
                if(i != p && p != k && k != i) all_num_vec.push_back(i*100+p*10+k);
            }
        }
    }
    while(n--) {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        for (auto i = all_num_vec.begin(); i!=all_num_vec.end(); i++) {
            if (*i != 0) {
                if(get_strike(num, *i) != strike || get_ball(num, *i) != ball) *i = 0;
            }
        }
    }
    int guess_num = 0;
    for(int k : all_num_vec) {
        if(k != 0) guess_num++;
    }
    cout << guess_num;
    return 0;
}