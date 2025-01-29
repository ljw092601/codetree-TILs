#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[100000];
int dp[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];

    for(int i=1; i<n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
    }

    int max_dp = -INT_MAX;
    for(int i=0; i<n; i++) max_dp = max(max_dp, dp[i]);
    cout << max_dp;

    return 0;
}
