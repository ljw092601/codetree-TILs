#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(2*n);
    for(int i=0; i<2*n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int min_diff = vec[2*n-1] - vec[0];
    for(int i=0; i<n; i++) {
        int diff = vec[n+i] - vec[i];
        if(min_diff > diff) min_diff = diff;
    }
    cout << min_diff;
    return 0;
}