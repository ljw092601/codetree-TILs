#include <iostream>
#include <climits>
using namespace std;

int N, M;
int w[100], v[100];
int dp[30000];
int temp[30000];

void copy() {
    for(int i=0; i<=M; i++) {
        dp[i] = temp[i];
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    dp[0] = 1;
    temp[0] = 1;

    for(int i=0; i<N; i++) {
        for(int p=0; p<M; p++) {
            if(dp[p]) temp[p + w[i]] = max(dp[p + w[i]], dp[p] + v[i]);
        }
        copy();
    }

    int max_val = 0;
    for(int i=1; i<=M; i++) {
        max_val = max(max_val, dp[i]);
    }

    cout << max_val-1;

    return 0;
}
