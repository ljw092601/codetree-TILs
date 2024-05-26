#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, p;
    cin >> n;
    p = n;
    vector<int> num_vec;
    while(p--) {
        int num;
        cin >> num;
        num_vec.push_back(num);
    }
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (i == 0 || num_vec[i] != num_vec[i-1]) cnt++;
    }
    cout << cnt;
    return 0;
}