#include <iostream>

using namespace std;

string s;
string t;

int dp[1005][1005];

int main() {
    cin >> s;
    cin >> t;

    int n = s.length();
    int m = t.length();

    bool find = false;
    for(int i=0; i<n; i++) {
        if(s[i] == t[0]) find = true;
        if(find) dp[i][0] = 1;
    }

    find = false;
    for(int i=0; i<m; i++) {
        if(s[0] == t[i]) find = true;
        if(find) dp[0][i] = 1;
    }

    for(int i=1; i<n; i++) {
        for(int p=1; p<m; p++) {
            if(s[i] == t[p]) dp[i][p] = dp[i-1][p-1] + 1;
            else {
                dp[i][p] = max(dp[i-1][p], dp[i][p-1]);
            }
        }
    }

    cout << n + m - dp[n-1][m-1];
    return 0;
}
