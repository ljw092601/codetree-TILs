#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int min = 100;
    for (int i=0; i<n; i++) {
        cin >> vec[i];
        if (min > vec[i]) min = vec[i];
    }
    int sec_min = 101;
    for (int v : vec) {
        if (v != min && sec_min > v) sec_min = v;
    }
    if (sec_min == 101) {
        cout << -1;
        return 0;
    }
    bool find = false;
    int idx = 0;
    for(int i=0; i<n; i++) {
        if(vec[i] == sec_min) {
            if (!find) {
                idx = i+1;
                find = true;
            }
            else {
                cout << -1;
                return 0;
            }
        }
    }
    cout << idx;
    return 0;
}