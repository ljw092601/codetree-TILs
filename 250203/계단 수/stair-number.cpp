#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int n;
int dp[1002][10];
// dp[x][y] = x번째 자리가 y일때 가능한 가짓수;

int main() {
    cin >> n;

    for(int i=1; i<10; i++) {
        dp[1][i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int p=0; p<10; p++) {
            if(p == 0) {
                dp[i+1][1] = (dp[i+1][1] + dp[i][p]) % MOD;
            }
            else if(p == 9) {
                dp[i+1][8] = (dp[i+1][8] + dp[i][p]) % MOD;
            }
            else {
                dp[i+1][p+1] = (dp[i+1][p+1] + dp[i][p]) % MOD;
                dp[i+1][p-1] = (dp[i+1][p-1] + dp[i][p]) % MOD;
            }
        }
    }

    int sum = 0;
    for(int i=0; i<10; i++) {
        sum = (sum + dp[n][i]) % MOD;
    }
    cout << sum;

    return 0;
}
