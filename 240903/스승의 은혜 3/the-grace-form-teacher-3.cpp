#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, money;
    cin >> n >> money;
    vector<int> price_vec(n,0);
    vector<int> deli_vec(n,0);
    for (int i=0; i<n; i++) {
        cin >> price_vec[i] >> deli_vec[i];
    }
    int max_gift = 0;
    for (int i=0; i<n; i++) {
        price_vec[i] /= 2;
        vector<int> hole_cost(n,0);
        for(int p=0; p<n; p++) {
            hole_cost[p] = price_vec[p] + deli_vec[p];
        }
        // for(int p=0; p<n; p++) {
        //     cout << hole_cost[p] << endl;
        // }
        sort(hole_cost.begin(), hole_cost.end());
        
        int hole_price = 0;
        int gift = 0;
        for(int c : hole_cost) {
            hole_price += c;
            if(hole_price <= money) gift++;
            else break;
        }
        // cout << gift << endl;
        if (max_gift < gift) max_gift = gift;
        price_vec[i] *= 2;
    }
    cout << max_gift;
    return 0;
}