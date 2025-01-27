#include <iostream>

using namespace std;

int n;
int profit[101];
int dp[300];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> profit[i];
    }

    for(int i=1; i<=n; i++) {
        dp[i] = profit[i];
        for(int p=1; p<i; p++) {
            dp[i] = max(dp[i], dp[i-p] + profit[p]);
        }
    }

    cout << dp[n];

    return 0;
}
