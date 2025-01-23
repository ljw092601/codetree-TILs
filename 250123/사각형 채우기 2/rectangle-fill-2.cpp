#include <iostream>

using namespace std;

int n;
int dp[1001];

int square_case(int k) {
    if(dp[k]) return dp[k];
    if(k <= 0) return dp[k] = 1;
    if(k == 1) return dp[k] = 1;
    if(k == 2) return dp[k] = 3;

    return dp[k] = (square_case(k-1) + square_case(k-2)*2) % 10007;
}

int main() {
    cin >> n;

    cout << square_case(n);

    return 0;
}