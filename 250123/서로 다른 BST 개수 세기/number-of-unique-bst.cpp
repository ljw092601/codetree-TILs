#include <iostream>

using namespace std;

int n;
int dp[20];

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++) {
        dp[i] = 0;
        for(int p=1; p<=n; p++) {
            dp[i] += dp[i-p] * dp[p-1];
        }
    }

    cout << dp[n];

    return 0;
}
