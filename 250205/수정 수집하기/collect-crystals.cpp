#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, k;
string str;
int dp[1001][2][21];
// dp[x][y][z] x번째 수정이 떨어지고 현재 y위치에 있고 z번 움직였을때 얻을 수 있는 최대 수정

void init() {
    for(int i=0; i<1001; i++) {
        for(int p=0; p<2; p++) {
            for(int k=0; k<21; k++) {
                dp[i][p][k] = INT_MIN;
            }
        }
    }
}

void print(int i) {
    for(int p=0; p<2; p++) {
        for(int k=0; k<12; k++) {
            cout << (dp[i][p][k] < 0 ? -1 : dp[i][p][k]) << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> k;
    cin >> str;
    init();

    if(str[0] == 'L') {
        dp[0][0][0] = 1;
    }
    else {
        dp[0][0][0] = 0;
        dp[0][1][1] = 1;
    }
    

    for(int i=1; i<n; i++) {
        for(int p=0; p<=k; p++) {
            if(str[i] == 'L') {
                if(0 <= dp[i-1][0][p]) {
                    dp[i][0][p] = max(dp[i][0][p], dp[i-1][0][p] + 1);
                }
                else if(0 <= dp[i-1][1][p]) {
                    if(p<k) dp[i][0][p+1] = max(dp[i][0][p+1], dp[i-1][1][p] + 1);
                    dp[i][1][p] = max(dp[i][1][p], dp[i-1][1][p]);
                }
            }
            else {
                if(0 <= dp[i-1][1][p]) {
                    dp[i][1][p] = max(dp[i][1][p], dp[i-1][1][p] + 1);
                }
                else if(0 <= dp[i-1][0][p]) {
                    if(p<k) dp[i][1][p+1] = max(dp[i][1][p+1], dp[i-1][0][p] + 1);
                    dp[i][0][p] = max(dp[i][0][p], dp[i-1][0][p]);
                }
            }
        }
    }

    int max_dp = 0;
    for(int i=0; i<=k; i++) {
        max_dp = max(max_dp, dp[n-1][0][i]);
        max_dp = max(max_dp, dp[n-1][1][i]);
    }
    // print(0);
    // print(1);
    // print(2);
    // print(3);
    // print(4);
    cout << max_dp;

    return 0;
}
