#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = n;
    vector<int> cows;
    while(t--) {
        int num;
        cin >> num;
        cows.push_back(num);
    }
    int pair = 0;
    for (int i=0; i<n; i++) {
        for(int p=i+1; p<n; p++) {
            if (cows[i] <= cows[p]) {
                for(int q=p+1; q<n; q++) {
                    if (cows[p] <= cows[q]) pair++;
                }
            }
        }
    }
    cout << pair;
    return 0;
}