#include <iostream>

using namespace std;

int N;

int dp[50];

void fibo(int n) {
    if(n == N+1) return;
    dp[n] = dp[n-1] + dp[n-2];
    fibo(n+1);
}

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 1;

    fibo(3);

    cout << dp[N];

    return 0;
}
