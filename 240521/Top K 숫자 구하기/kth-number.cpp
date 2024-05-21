#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> n_vec;
    while(n--) {
        int num;
        cin >> num;
        n_vec.push_back(num);
    }
    sort(n_vec.begin(), n_vec.end());
    cout << n_vec[k-1];
    return 0;
}