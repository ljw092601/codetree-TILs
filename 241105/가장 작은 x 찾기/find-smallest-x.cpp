#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> min_vec(n);
    vector<int> max_vec(n);
    for(int i=0; i<n; i++) {
        cin >> min_vec[i] >> max_vec[i];
    }
    for (int i=min_vec[0]/2; i<=max_vec[0]/2; i++) {
        int predict = i;
        bool fail = false;
        for (int p=0; p<n; p++) {
            predict *= 2;
            if (min_vec[p] <= predict && predict <= max_vec[p]);
            else {
                fail = true;
                break;
            }
        }
        if (!fail) {
            cout << i;
            return 0;
        }
    }
    return 0;
}