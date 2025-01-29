#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int nums[100];
vector<vector<int>> dp (100, vector<int>(41, 0));
//dp[x][y] x번째 숫자의 합이 y인 경우의 수

void print_dp() {
    for(int i=0; i<=N; i++) {
        for(int p=0; p<=40; p++) cout << (dp[i][p]) << ' ';
        cout << endl;
    }
}

bool in_range(int x) {
    return 0 <= x && x <= 40;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    dp[0][20 + nums[0]]++;
    dp[0][20 - nums[0]]++;

    for(int i=0; i<N-1; i++) {
        for(int p=0; p<41; p++) {
            if(dp[i][p]) {
                if(in_range(p+nums[i+1])) dp[i+1][p+nums[i+1]] += dp[i][p];
                if(in_range(p-nums[i+1])) dp[i+1][p-nums[i+1]] += dp[i][p];
            }
        }
    }


    // print_dp();
    cout << dp[N-1][M+20];

    return 0;
}
