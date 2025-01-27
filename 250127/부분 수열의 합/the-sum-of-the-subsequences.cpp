#include <iostream>

using namespace std;

int n, m;
int A[100];
int dp[30000];
int temp[30000];

void copy() {
    for(int i=0; i<=m; i++) {
        dp[i] = temp[i];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = 1;
    temp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            if(dp[p]) temp[p + A[i]]++;
        }
        copy();
    }

    cout << (dp[m] ? "Yes" : "No");

    return 0;
}
