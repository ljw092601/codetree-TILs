#include <iostream>

using namespace std;

int n;
int dp[1001];

int jump_case(int k) {
    if(dp[k]) return dp[k];
    if(k <= 1) return dp[k] = 0;
    if(k == 2 || k == 3) return dp[k] = 1;

    return dp[k] = (jump_case(k-2) + jump_case(k-3)) % 10007;
}

int main() {
    cin >> n;

    cout << jump_case(n);

    return 0;
}