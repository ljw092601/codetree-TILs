#include <iostream>

using namespace std;

string s;
string p;

bool same(int si, int pi) {
    return s[si] == p[pi] || p[pi] == '.';
}

bool dp[22][22];


int main() {
    cin >> s;
    cin >> p;

    int a = s.size();
    int b = p.size();
    s = " " + s;
    p = " " + p;

    dp[0][0] = true;

    for(int i=0; i<=a; i++) {
        for(int j=0; j<b; j++) {
            if (!dp[i][j]) continue;

            if (p[j+2] == '*') {
                dp[i][j+2] = true;

                for(int set=i+1; set<=a; set++) {
                    if(!same(set, j+1)) break;
                    dp[set][j+2] = true;
                }
            }
            else {
                if(same(i+1, j+1)) dp[i+1][j+1] = true;
            }
        }
    }
    
    cout << (dp[a][b] ? "true" : "false");

    return 0;
}
