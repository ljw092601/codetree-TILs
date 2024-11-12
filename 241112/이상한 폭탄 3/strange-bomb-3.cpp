#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool is_boom(const vector<int>& v, int i, int k) {
    for (int p = i-k; p<= i+k; p++) {
        if (0 <= p && p<v.size() && p != i){
            if (v[i] == v[p]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }
    map<int,int> boom;
    for (int i=0; i<n; i++) {
        if (is_boom(vec, i, k)) boom[vec[i]]++;
    }
    if (boom.empty()) {
        cout << 0;
        return 0;
    }
    int max_boom = 0;
    int max_boom_num = 0;
    for (auto b : boom) {
        if (max_boom <= b.second) {
            max_boom = b.second;
            max_boom_num = b.first;
        }
    }
    cout << max_boom_num;

    return 0;
}