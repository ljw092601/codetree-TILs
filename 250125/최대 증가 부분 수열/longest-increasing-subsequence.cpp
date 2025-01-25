#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M[1000];
int dp[1000];

void print_max() {
    int max_dp = 0;
    for(int i=0; i<N; i++) max_dp = max(max_dp, dp[i]);
    cout << max_dp;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    for(int i=0; i<N; i++) {
        int max_dp = 1;
        for(int p=0; p<i; p++) {
            if (M[p] < M[i]) {
                max_dp = max(max_dp, dp[p]+1);
            }
        }
        dp[i] = max_dp;
    }

    print_max();

    return 0;
}
