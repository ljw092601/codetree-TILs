#include <iostream>

using namespace std;

int N, M;
int s[200], e[200], v[200];
int dp[200][200];
// dp[x][y] x일에 마지막으로 입은 옷이 y일때, 얻는 최고 점수

void print() {
    for(int i=1; i<=M; i++) {
        for(int p=0; p<N; p++) {
            cout << dp[i][p] << ' ';
        }
        cout << endl;
    }
}

bool can_wear(int day, int cloth) {
    return s[cloth] <= day+1 && day+1 <= e[cloth];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> e[i] >> v[i];
    }

    
    for(int i=1; i<=M; i++) {
        for(int p=0; p<N; p++) {
            if(can_wear(i, p)) {
                int max_diff = 0;
                int max_cloth;
                for(int k=0; k<N; k++) {
                    if(can_wear(i-1, k)) {
                        int diff = abs(v[k] - v[p]);
                        if (max_diff < diff) {
                            max_diff = diff;
                            max_cloth = k;
                        }
                    }
                }
                dp[i][p] = dp[i-1][max_cloth] + max_diff;
            }
        }
    }
    
    int max_dp = 0;
    for(int i=0; i<N; i++) {
        max_dp = max(max_dp, dp[M-1][i]);
    }
    cout << max_dp;
    //print();

    return 0;
}