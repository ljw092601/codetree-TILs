#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> cont_vec;
    int cont = 0;
    for (int i=0; i<n; i++) {
        if (i == 0 || num_vec[i] * num_vec[i-1] < 0) {
            cont_vec.push_back(cont);
            cont = 0;
        }
        cont++;
    }
    auto max = max_element(cont_vec.begin(), cont_vec.end());
    cout << *max;
    return 0;
}