#include <iostream>
#include <string>

using namespace std;

string A;
string B;

string dp[1005][1005];
//dp[x][y] = A의 x번째, B의 y번째 문자까지의 최장 공통 부분 순열

int main() {
    cin >> A;
    cin >> B;

    int N = A.length();
    int M = B.length();

    bool find = false;
    for(int i=0; i<N; i++) {
        if(A[i] == B[0]) find = true;
        if(find) dp[i][0] = B[0];
    }

    find = false;
    for(int i=0; i<M; i++) {
        if(B[i] == A[0]) find = true;
        if(find) dp[0][i] = A[0];
    }

    for(int i=1; i<N; i++) {
        for(int p=1; p<M; p++) {
            if(A[i] == B[p]) dp[i][p] = dp[i-1][p-1] + A[i];
            else dp[i][p] = dp[i-1][p-1];
        }
    }
    
    cout << dp[N-1][M-1];

    return 0;
}
