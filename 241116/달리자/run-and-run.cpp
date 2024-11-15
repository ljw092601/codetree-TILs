#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> before(n);
    vector<int> after(n);
    for(int i=0; i<n; i++) {
        cin >> before[i];
    }
    for(int i=0; i<n; i++) {
        cin >> after[i];
    }
    int total_move = 0;
    for(int i=0; i<n; i++) {
        if(before[i] > after[i]) {
            int move = before[i] - after[i];
            for (int p = i+1; p<n; p++) {
                if (before[p] < after[p]) {
                    before[p] += move;
                    total_move += move * (p - i);
                    break;
                }
            }
        }
    }
    cout << total_move;
    return 0;
}