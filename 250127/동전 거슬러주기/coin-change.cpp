#include <iostream>
#include <climits>
using namespace std;

int N, M;
int coin[100];
int dp[30000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    for(int i=1; i<=M; i++) {
        dp[i] = 1e9;
    }

    for(int i=0; i<M; i++) {
        for(int p=0; p<N; p++) {
            dp[i+coin[p]] = min(dp[i+coin[p]], dp[i] + 1);
        }
    }

    cout << (dp[M] == 1e9 ? -1 : dp[M]);

    return 0;
}
