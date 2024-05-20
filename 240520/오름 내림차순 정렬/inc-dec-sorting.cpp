#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num_vec;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        num_vec.push_back(num);
    }
    sort(num_vec.begin(), num_vec.end());
    for (int num : num_vec) {
        cout << num << " ";
    }
    cout << endl;
    sort(num_vec.begin(), num_vec.end(), greater<int>());
    for (int num : num_vec) {
        cout << num << " ";
    }
    return 0;
}