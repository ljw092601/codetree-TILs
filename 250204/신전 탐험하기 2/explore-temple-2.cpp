#include <iostream>
#include <algorithm>
using namespace std;

int n;
int l[1001], m[1001], r[1001];
int dp[1002][3][3];
// dp[x][y][z] = z방향으로 출발해 x층에서 y방향으로 갔을때 얻을 수 있는 최대 보물 수

int trasure (int stage, int dir) {
    if(dir == 0) return l[stage];
    if(dir == 1) return m[stage];
    if(dir == 2) return r[stage];
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> m[i] >> r[i];
    }

    dp[1][0][0] = l[1];
    dp[1][1][1] = m[1];
    dp[1][2][2] = r[1];

    for(int i=2; i<n; i++) {
        for(int p=0; p<3; p++) {
            for(int k=0; k<3; k++) {
                if(dp[i-1][p][k]) {
                    dp[i][(p+1)%3][k] = max(dp[i][(p+1)%3][k], dp[i-1][p][k] + trasure(i, (p+1)%3));
                    dp[i][(p+2)%3][k] = max(dp[i][(p+2)%3][k], dp[i-1][p][k] + trasure(i, (p+2)%3));
                }
            }
        }
    }

    for(int p=0; p<3; p++) {
        for(int k=0; k<3; k++) {
            if(dp[n-1][p][k]) {
                if((p+1)%3 != k) dp[n][(p+1)%3][k] = max(dp[n][(p+1)%3][k], dp[n-1][p][k] + trasure(n, (p+1)%3));
                if((p+2)%3 != k) dp[n][(p+2)%3][k] = max(dp[n][(p+2)%3][k], dp[n-1][p][k] + trasure(n, (p+2)%3));
            }
        }
    }
    
    int max_dp = 0;
    for(int p=0; p<3; p++) {
        for(int k=0; k<3; k++) {
            max_dp = max(max_dp, dp[n][p][k]);
        }
    }
    cout << max_dp;

    return 0;
}
