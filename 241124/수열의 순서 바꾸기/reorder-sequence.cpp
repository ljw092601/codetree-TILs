#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }
    int answer = 0;
    for(int i=n-1; i>0; i--) {
        if (vec[i-1] > vec[i]) answer = i;
    }
    cout << answer;
    return 0;
}