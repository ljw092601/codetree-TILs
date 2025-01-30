#include <iostream>

using namespace std;

int n;
int dp[1005][3][3];
// dp[x][y][z] x번째까지 수열에서 연속된 B 개수 y개, 전체 T개수 z개인 수열의 경우의 수

int main() {
    cin >> n;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    for(int i=0; i<n; i++) {
        for(int p=0; p<3; p++) {
            for(int k=0; k<3; k++) {
                if(p == 2 && k == 2) {
                    dp[i+1][0][k] += dp[i][p][k];
                }
                else if(p == 2) {
                    dp[i+1][0][k] += dp[i][p][k];
                    dp[i+1][0][k+1] += dp[i][p][k];
                }
                else if(k == 2) {
                    dp[i+1][0][k] += dp[i][p][k];
                    dp[i+1][p+1][k] += dp[i][p][k];
                }
                else {
                    dp[i+1][p+1][k] += dp[i][p][k];
                    dp[i+1][0][k+1] += dp[i][p][k];
                    dp[i+1][0][k] += dp[i][p][k];
                }
            }
        }
    }

    int sum = 0;
    for(int i=0; i<3; i++) {
        for(int p=0; p<3; p++) {
            sum += dp[n][i][p];
        }
    }
    cout << sum;

    return 0;
}
