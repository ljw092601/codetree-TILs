#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b, st, ed;
    cin >> a >> b;
    vector<int> arr(a, 0);
    while(b--) {
        cin >> st >> ed;
        for (st; st<=ed; st++) {
            arr[st] += 1;
        }
    }
    int max = 0;
    for (int i=0; i<a; i++) {
        if(arr[i] > max) max = arr[i];
    }
    cout << max;
    return 0;
}