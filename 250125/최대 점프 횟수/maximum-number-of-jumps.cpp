#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++) {
        int max_dp = 0;
        for(int p=0; p<i; p++) {
            if (i - p <= arr[p] && dp[p]) {
                max_dp = max(max_dp, dp[p]+1);
            }
        }
        dp[i] = max_dp;
    }

    int max_dp = 0;
    for(int i=0; i<n; i++) {
        max_dp = max(max_dp, dp[i]);
    }
    cout << max_dp-1;

    return 0;
}
