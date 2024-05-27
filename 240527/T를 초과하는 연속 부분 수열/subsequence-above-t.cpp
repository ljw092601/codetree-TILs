#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t, p;
    cin >> n >> t;
    p = n;
    vector<int> num_vec;
    while(p--) {
        int num;
        cin >> num;
        num_vec.push_back(num);
    }
    vector<int> cont_vec;
    int cont = 0;
    for (int i=0; i<n; i++) {
        cont++;
        if (num_vec[i+1] <= t || num_vec[i] <= t) {
            cont_vec.push_back(cont);
            cont = 0;
        }
    }
    cont_vec.push_back(cont);
    auto max = max_element(cont_vec.begin(), cont_vec.end());
    cout << *max;
    return 0;
}