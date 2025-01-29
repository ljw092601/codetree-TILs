#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, k;
int numbers[100000];
vector<vector<int>> dp (100002, vector<int>(12, INT_MIN));
// dp[x][y] = x번째 까지의 연속합중 음수가 y개인 연속합의 최댓값

void print_dp() {
    for(int i=0; i<=n; i++) {
        for(int p=0; p<=k; p++) cout << (dp[i][p]) << ' ';
        cout << endl;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    if (numbers[0] < 0) dp[0][1] = numbers[0];
    else dp[0][0] = numbers[0];

    for(int i=1; i<n; i++) {
        for(int p=0; p<=k; p++) {
            if(numbers[i] < 0) {
                dp[i][0] = numbers[i];
                dp[i][p+1] = dp[i-1][p] + numbers[i];
            }
            else {
                dp[i][p] = max(dp[i-1][p] + numbers[i], numbers[i]);
            }
        }
    }

    int max_dp = INT_MIN;
    for(int i=0; i<n; i++) {
        for(int p=0; p<=k; p++) {
            max_dp = max(max_dp, dp[i][p]);
        }
    }

    //print_dp();
    cout << max_dp;

    return 0;
}
