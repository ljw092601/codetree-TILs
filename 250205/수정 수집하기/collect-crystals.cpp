#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
string str;
int dp[1005][2][25];
// dp[x][y][z] x번째 수정이 떨어지고 현재 y위치에 있고 z번 움직였을때 얻을 수 있는 최대 수정

int main() {
    cin >> n >> k;
    cin >> str;

    if(str[0] == 'L') {
        dp[0][0][0] = 2;
    }
    else {
        dp[0][0][0] = 1;
        dp[0][1][1] = 2;
    }
    

    for(int i=1; i<n; i++) {
        for(int p=0; p<=k; p++) {
            if(str[i] == 'L') {
                if(dp[i-1][0][p]) {
                    dp[i][0][p] = max(dp[i][0][p], dp[i-1][0][p] + 1);
                }
                else if(dp[i-1][1][p] && p < k) {
                    dp[i][0][p+1] = max(dp[i][0][p+1], dp[i-1][1][p] + 1);
                    dp[i][1][p] = max(dp[i][1][p], dp[i-1][1][p]);
                }
            }
            else {
                if(dp[i-1][1][p]) {
                    dp[i][1][p] = max(dp[i][1][p], dp[i-1][1][p] + 1);
                }
                else if(dp[i-1][0][p] && p < k) {
                    dp[i][1][p+1] = max(dp[i][1][p+1], dp[i-1][0][p] + 1);
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
    cout << max_dp - 1;

    return 0;
}
