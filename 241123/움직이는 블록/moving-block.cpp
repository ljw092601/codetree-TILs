#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    int block = sum / n;
    int answer = 0;
    for(int v : vec) {
        if (v - block > 0) answer += v - block;
    }
    cout << answer;
    return 0;
}