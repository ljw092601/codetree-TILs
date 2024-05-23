#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> bin_vec;
    while(n > 0) {
        bin_vec.emplace_back(n%2);
        n /= 2;
    }
    for (int i= bin_vec.size()-1; i >= 0; i--) cout << bin_vec[i];
    return 0;
}