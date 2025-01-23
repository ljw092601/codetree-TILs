#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
int grid[100][100];
pair<int,int> dp[100][100];

pair<int,int> find_small_diff(int x, int y) {
    int diff1 = dp[x-1][y].first - dp[x-1][y].second;
    int diff2 = dp[x][y-1].first - dp[x][y-1].second;
    if (diff1 < diff2) return dp[x-1][y];
    else return dp[x][y-1];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = make_pair(grid[0][0], grid[0][0]);

    for (int i = 1; i < n; i++) {
        dp[0][i] = make_pair(max(dp[0][i-1].first, grid[0][i]), min(dp[0][i-1].second, grid[0][i]));
        dp[i][0] = make_pair(max(dp[i-1][0].first, grid[i][0]), min(dp[i-1][0].second, grid[i][0]));
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pair<int,int> small_diff = find_small_diff(i,j);
            dp[i][j] = make_pair(max(small_diff.first, grid[i][j]), min(small_diff.second, grid[i][j]));
        }
    }

    cout << dp[n-1][n-1].first - dp[n-1][n-1].second;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j].first << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << dp[i][j].second << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}
