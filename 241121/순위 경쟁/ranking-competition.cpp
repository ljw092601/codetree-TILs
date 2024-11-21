#include <iostream>
using namespace std;

int cal_top(int a, int b, int c) {
    if (a == b && b == c) return 0;
    if (a > b && a > c) return 1;
    if (b > a && b > c) return 2;
    if (c > b && c > a) return 3;
    if (a == b && a > c) return 4;
    if (b == c && b > a) return 5;
    if (a == c && a > b) return 6;
}

int main() {
    int n;
    cin >> n;
    int change = 0;
    int top = 0; // both:0, A:1, B:2, C:3, A/B:4, B/C:5, A/C:6
    int A = 0;
    int B = 0;
    int C = 0;
    while(n--) {
        int score;
        char player;
        cin >> player >> score;
        if (player == 'A') A += score;
        else if(player == 'B') B += score;
        else C += score;
        int new_top = cal_top(A,B,C);
        if (top != new_top) change++;
        top = new_top;
    }
    cout << change;
    return 0;
}