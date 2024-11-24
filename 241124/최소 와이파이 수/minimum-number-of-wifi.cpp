#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }
    int idx = 0;
    int wifi = 0;
    while(idx < n) {
        if (vec[idx] == 1) {
            idx += m*2;
            wifi++;
        }
        idx++;
    }
    cout << wifi;
    return 0;
}