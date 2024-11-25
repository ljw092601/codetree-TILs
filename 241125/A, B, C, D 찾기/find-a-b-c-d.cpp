#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec(15);
    for(int i=0; i<15; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << 
    vec[14] - vec[0] - vec[1] - vec[2];
    return 0;
}