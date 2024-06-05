#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> n_vec(n,0);
    for(int i=0; i<n; i++) {
        cin >> n_vec[i];
    }
    int max_sum = 0;
    for (int i=0; i<n-k+1; i++) {
        int sum = 0;
        for(int p=0; p<k; p++) {
            sum += n_vec[i+p];
        }
        if(sum > max_sum) max_sum=sum;
    }
    cout << max_sum;
    return 0;
}