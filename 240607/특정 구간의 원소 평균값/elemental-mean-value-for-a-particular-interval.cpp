#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> n_vec(n, 0);
    for (int i=0; i<n; i++) {
        cin >> n_vec[i];
    }
    int cases = 0;
    for (int i=0; i<n; i++) {
        for(int p=1; p<=n-i; p++) {
            float aver = 0;
            for (int k=i; k<i+p; k++) {
                aver += n_vec[k];
            }
            aver /= p;
            for (int k=i; k<i+p; k++) {
                if(n_vec[k] == aver) {
                    cases++;
                    break;
                }
            }
        }
    }
    cout << cases;

    return 0;
}