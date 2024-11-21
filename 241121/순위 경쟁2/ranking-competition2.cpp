#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int change = 0;
    int top = 0; // both:0, A:1, B:2
    int A = 0;
    int B = 0;
    while(n--) {
        int score;
        char player;
        cin >> player >> score;
        if (player == 'A') A += score;
        else B += score;
        int new_top = 0;
        if (A == B) new_top = 0;
        else if (A > B) new_top = 1;
        else new_top = 2;
        if (top != new_top) change++;
        top = new_top;
    }
    cout << change;
    return 0;
}