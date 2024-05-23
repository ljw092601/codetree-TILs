#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> bin_vec;
    while(true) {
        if (n<b) {
            bin_vec.emplace_back(n);
            break; 
        }
        bin_vec.emplace_back(n%b);
        n /= b;
    }
    for (int i= bin_vec.size()-1; i >= 0; i--) cout << bin_vec[i];
    return 0;
}