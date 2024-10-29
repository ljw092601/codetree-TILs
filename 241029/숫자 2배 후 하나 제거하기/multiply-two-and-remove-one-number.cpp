#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> num_vec (n, 0);
    for (int i=0; i<n; i++) {
        cin >> num_vec[i];
    }
    
    int min_sum = INT_MAX;
    for (int i=0; i<n; i++) {
        for (int p=0; p<n; p++) {
            vector<int> new_vec = num_vec;
            new_vec[i] *= 2;
            new_vec.erase(new_vec.begin() + p);
            int sum = 0;
            for (int k=0; k<n-2; k++) {
                sum += abs(new_vec[k] - new_vec[k+1]);
            }
            if(min_sum > sum) min_sum = sum;
        }
    }
    cout << min_sum;
    return 0;
}