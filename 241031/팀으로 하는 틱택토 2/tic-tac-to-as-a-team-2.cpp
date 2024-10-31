#include <iostream>
#include <string>
using namespace std;

bool is_success(int a, int b, int c, int team1, int team2) {
    if (a == b && b == c) return false;
    if (a == team1 || a == team2){
        if (b == team1 || b == team2){
            if (c == team1 || c == team2) {
                return true;
            }
        }
    }
    return false;
}

bool can_win(int arr[3][3], int a, int b) {
    for (int i=0; i<3; i++) {
        if (is_success(arr[i][0], arr[i][1], arr[i][2], a, b)) return true;
        if (is_success(arr[0][i], arr[1][i], arr[2][i], a, b)) return true;
    }
    if (is_success(arr[0][0], arr[1][1], arr[2][2], a, b)) return true;
    if (is_success(arr[0][2], arr[1][1], arr[2][0], a, b)) return true;
    return false;
}

int main() {
    int tic[3][3] = {0,};
    string s;
    for (int i=0;i<3;i++) {
        cin >> s;
        for(int p=0; p<3; p++) {
            tic[i][p] = s[p] - '0';
        }
    }

    int win = 0;
    for (int i=1; i<9; i++) {
        for (int p=i+1; p<10; p++) {
            if (can_win(tic, i, p)) win++;
        }
    }
    cout << win;

    return 0;
}