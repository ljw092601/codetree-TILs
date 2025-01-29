#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n;
int first_cards[1000];
int second_cards[1000];
vector<vector<int>> dp (1002, vector<int>(1002, INT_MIN));
// dp[x][y] = 상대카드가 x번째, 내 카드가 y번쨰 카드일때 얻을 수 있는 최대 점수

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> first_cards[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> second_cards[i];
    }

    dp[0][0] = 0;

    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if (first_cards[i] > second_cards[p]) dp[i][p+1] = max(dp[i][p+1], dp[i][p] + second_cards[p]);
            else {
                dp[i+1][p+1] = max(dp[i+1][p+1], dp[i][p]);
                dp[i+1][p] = max(dp[i+1][p], dp[i][p]);
            }
        }
    }

    int max_dp = 0;
    for(int i=0; i<n; i++) {
        max_dp = max(max_dp, dp[i][n]);
        max_dp = max(max_dp, dp[n][i]);
    }
    cout << max_dp;

    return 0;
}
