#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, money;
    cin >> n >> money;
    vector<int> wish_list(n,0);
    for(int i=0; i<n; i++) {
        cin >> wish_list[i];
    }
    int max_gift_num = 0;
    for(int i=0; i<n; i++) {
        vector<int> copy(wish_list);
        copy[i] /= 2;
        sort(copy.begin(), copy.end());
        int cost = 0;
        int gift_num = 0;
        while(cost <= money) {
            cost += copy[gift_num];
            gift_num++;
        }
        if(max_gift_num < gift_num) max_gift_num = gift_num;
    }
    cout << max_gift_num-1;
    return 0;
}