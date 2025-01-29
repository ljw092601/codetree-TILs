#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int coin[1001];
vector<vector<int>> dp (2000, vector<int>(4, INT_MIN)); 
//dp[x][y] = x층에서 y번 1계단 올라가기를 사용했을때 최대 동전개수

void print_dp() {
    for(int i=1; i<=n; i++) {
        for(int p=0; p<=3; p++) cout << (dp[i][p] < 0 ? 0 : dp[i][p]) << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    dp[1][1] = coin[1];
    dp[2][0] = coin[2];
    dp[2][2] = coin[1] + coin[2];

    for(int i=3; i<=n; i++) {
        for(int p=0; p<=3; p++) {
            if (p == 0) dp[i][p] = dp[i-2][p] + coin[i];
            else dp[i][p] = max(dp[i-2][p] + coin[i], dp[i-1][p-1] + coin[i]);
        }
    }

    int max_dp = 0;
    for(int i=0; i<=3; i++) max_dp = max(max_dp, dp[n][i]);
    cout << max_dp;

    //print_dp();

    return 0;
}
