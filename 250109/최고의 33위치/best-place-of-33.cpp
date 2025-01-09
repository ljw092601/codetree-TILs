#include <iostream>

using namespace std;

int N;
int grid[20][20];

int cal_num(int a, int b) {
    int num = 0;
    for(int i=0; i<3; i++) {
        for(int p=0; p<3; p++) {
            if(grid[a+i][b+p]) num++;
        }
    }
    return num;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int max_coin = 0;

    for(int i=0; i<=N-3; i++) {
        for(int p=0; p<=N-3; p++) {
            max_coin = max(max_coin, cal_num(i, p));
        }
    }

    cout << max_coin;

    return 0;
}
