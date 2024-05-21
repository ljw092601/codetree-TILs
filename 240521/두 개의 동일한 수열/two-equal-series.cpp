#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a_vec;
    vector<int> b_vec;
    int n;
    cin >> n;
    int n1 = n;
    while(n1--) {
        int a;
        cin >> a;
        a_vec.push_back(a);
    }
    int n2 = n;
    while(n2--) {
        int b;
        cin >> b;
        b_vec.push_back(b);
    }
    sort(a_vec.begin(), a_vec.end());
    sort(b_vec.begin(), b_vec.end());
    bool is_same = true;
    for (int i=0; i<n; i++) {
        if(a_vec[i] != b_vec[i]) is_same = false;
    }
    cout << ((is_same) ? "Yes" : "No") << endl;
    return 0;
}