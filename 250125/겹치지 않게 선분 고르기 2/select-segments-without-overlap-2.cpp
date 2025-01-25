#include <iostream>

using namespace std;

int n;
int x1[1000];
int x2[1000];
int link[1000];
int dp[1000];

void init_link() {
    for(int i=0; i<n; i++) {
        link[i] = -1;
    }
}

bool is_over(int idx1, int idx2) {
    return (x1[idx1] <= x1[idx2] && x1[idx2] <= x2[idx1]) || (x1[idx2] <= x1[idx1] && x1[idx1] <= x2[idx2]);
}

bool can_pick(int link_i, int pick_i) {
    while(link_i >= 0) {
        if(is_over(link_i, pick_i)) return false;
        link_i = link[link_i];
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i];
    }

    init_link();

    for(int i=0; i<n; i++) {
        int max_dp = 1;
        for(int p=0; p<i; p++) {
            if(max_dp < dp[p]+1 && can_pick(p, i)) {
                max_dp = dp[p]+1;
                link[i] = p;
            }
        }
        dp[i] = max_dp;
    }

    int max_dp = 0;
    for(int i=0; i<n; i++) max_dp = max(max_dp, dp[i]);
    cout << max_dp;

    return 0;
}
