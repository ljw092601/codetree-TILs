#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> stu(n+1, 0);
    bool money = false;
    while(m--) {
        int punish;
        cin >> punish;
        stu[punish] += 1;
        if (stu[punish] >= k) {
            cout << punish;
            money = true;
            break;
        }
    }
    if (!money) cout << -1;
    return 0;
}