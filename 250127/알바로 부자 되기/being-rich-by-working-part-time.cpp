#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pt {
    int st;
    int ed;
    int money;
};

int N;
vector<pt> pt_arr;
int dp[1000];

bool can_take(int a, int b) {
    return pt_arr[a].ed < pt_arr[b].st;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        pt temp;
        cin >> temp.st >> temp.ed >> temp.money;
        pt_arr.emplace_back(temp);
    }

    sort(pt_arr.begin(), pt_arr.end(), [](pt a, pt b){return a.st < b.st;});

    for(int i=0; i<N; i++) {
        dp[i] = pt_arr[i].money;
        for(int p=0; p<i; p++) {
            if (can_take(p, i)) dp[i] = max(dp[i], dp[p]+pt_arr[i].money);
        }
    }

    int max_money = 0;
    for(int i=0; i<N; i++) {
        max_money = max(max_money, dp[i]);
    }

    cout << max_money;

    return 0;
}
