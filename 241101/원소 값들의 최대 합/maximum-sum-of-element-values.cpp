#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n ,m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }
    int max_sum = 0;
    for (int i=0; i<n; i++) {
        int sum = 0;
        int next = i;
        for (int p=0; p<m; p++) {
            sum += vec[next];
            next = vec[next] - 1;
        }
        if (max_sum < sum) max_sum = sum;
    }
    cout << max_sum;
    return 0;
}