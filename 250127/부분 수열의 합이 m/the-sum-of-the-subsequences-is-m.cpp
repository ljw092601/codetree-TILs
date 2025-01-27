#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[20000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i=1; i<=m; i++) {
        dp[i] = 1e9;
    }

    for(int i=0; i<n; i++) {
        for(int p=m; p>=0; p--) {
            if(dp[p] != 1e9) {
                dp[p+A[i]] = min(dp[p+A[i]], dp[p] + 1);
            }
        }
    }

    cout << (dp[m] == 1e9 ? -1 : dp[m]);

    return 0;
}
