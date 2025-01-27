#include <iostream>

using namespace std;

int n, m;
int e[100], t[100];
int dp[10001];  // dp[x] = x만큼 시간을 쓸때 얻는 최대 경험치
int temp[10001];

void copy() {
    for(int i=0; i<=10001; i++) {
        dp[i] = temp[i];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> e[i] >> t[i];
    }

    for(int i=0; i<n; i++) {
        for(int p=0; p<10001; p++) {
            if(dp[p]) temp[p + t[i]] = max(temp[p + t[i]], dp[p] + e[i]);
        }
        temp[t[i]] = max(temp[t[i]], e[i]);
        copy();
    }


    for(int p=0; p<10001; p++) {
        if(dp[p] >= m) {
            cout << p;
            return 0;
        }
    }

    cout << -1;

    return 0;
}
