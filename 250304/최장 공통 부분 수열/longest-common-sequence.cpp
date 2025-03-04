#include <iostream>
#include <string>

using namespace std;

int dp[1000][1000];
// dp[x][y] = A의 x번째, B의 y번째까지의 최장부분수열
string A, B;

int main() {
    cin >> A;
    cin >> B;
    int N = A.size();
    int M = B.size();


    for(int i=0; i<N; i++) {
        if(A[i] == B[0]) dp[i][0] = 1;
        else dp[i][0] = dp[i-1][0];
    }

    for(int i=0; i<M; i++) {
        if(A[0] == B[i]) dp[0][i] = 1;
        else dp[0][i] = dp[i-1][0];
    }

    for(int i=1; i<N; i++) {
        for(int p=1; p<M; p++) {
            if(A[i] == B[p]) {
                dp[i][p] = dp[i-1][p-1]+1;
            }
            else {
                dp[i][p] = max(dp[i-1][p], dp[i][p-1]);
            }
        }
    }

    // for(int i=0; i<N; i++) {
    //     for(int p=0; p<M; p++) {
    //         cout << dp[i][p] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << dp[N-1][M-1];


    return 0;
}
