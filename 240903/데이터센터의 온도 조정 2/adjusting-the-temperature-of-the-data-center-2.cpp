#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n,c,g,h;
    cin >> n >> c >> g >> h;
    vector<int> ta_vec(n,0);
    vector<int> tb_vec(n,0);
    for(int i=0; i<n; i++) {
        cin >> ta_vec[i] >> tb_vec[i];
    }
    auto min = min_element(ta_vec.begin(), ta_vec.end());
    auto max = max_element(tb_vec.begin(), tb_vec.end());
    int max_work = 0;
    for (int i = (*min)-1; i<=(*max)+1; i++) {
        int work = 0;
        for (int p=0; p<n; p++) {
            if (i < ta_vec[p]) work += c;
            if (ta_vec[p] <= i && i <= tb_vec[p]) work += g;
            if (tb_vec[p] < i) work += h;
        }
        if (max_work < work) max_work = work;
    }
    cout << max_work;
    return 0;
}