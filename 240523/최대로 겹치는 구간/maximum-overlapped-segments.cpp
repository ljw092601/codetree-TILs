#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[200] = {0,};
    int n;
    cin >> n;
    while(n--) {
        int x1, x2;
        cin >> x1 >> x2;
        for (int i=x1; i<x2; i++) {
            arr[i+100] += 1;
        }
    }
    int max = 0;
    for (int p : arr) {
        if (p > max) max = p;
    }
    cout << max;
    return 0;
}