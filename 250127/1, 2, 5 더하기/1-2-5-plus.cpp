#include <iostream>

using namespace std;

int n;
int dp[1001];

int sum_case(int k) {
    if(k <= 0) return 0;
    if(dp[k]) return dp[k];
    return dp[k] = (sum_case(k-1) + sum_case(k-2) + sum_case(k-5)) % 10007;
}

int main() {
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[5] = 9;

    cout << sum_case(n);

    return 0;
}
