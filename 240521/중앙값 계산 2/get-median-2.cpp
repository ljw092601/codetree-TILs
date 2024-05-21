#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100

int main() {
    int n;
    cin >> n;
    int arr[MAX_N];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if (i%2 == 0) {
            sort(arr, arr+i);
            cout << arr[i/2] << " ";
        }
    }
    return 0;
}