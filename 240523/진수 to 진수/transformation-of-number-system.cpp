#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n_to_decimal (int n, int nums) {
    int decimal = 0;
    int temp = nums;
    for(int i=0; pow(10, i)<=nums; i++) {
        decimal += (temp%10) * pow(n, i);
        temp /= 10;
    }
    return decimal;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int de = n_to_decimal(a, n);
    vector<int> bin_vec;
    while(true) {
        if (de<b) {
            bin_vec.emplace_back(de);
            break; 
        }
        bin_vec.emplace_back(de%b);
        de /= b;
    }
    for (int i= bin_vec.size()-1; i >= 0; i--) cout << bin_vec[i];
    return 0;
}