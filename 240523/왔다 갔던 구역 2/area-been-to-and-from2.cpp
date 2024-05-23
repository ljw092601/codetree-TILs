#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[2000] = {0,};
    int n;
    cin >> n;
    int start_p = 1000;
    while(n--) {
        int x;
        char LR;
        cin >> x >> LR;
        if (LR == 'L') {
            start_p -= x;
            for (int i=start_p; i<start_p+x; i++) {
                arr[i] += 1;
            }
        }
        else {
            start_p += x;
             for (int i=start_p-x; i<start_p; i++) {
                arr[i] += 1;
            }
        }
    }
    int GT2 = 0;
    for (int p : arr) {
        if (p >= 2) GT2++;
    }
    cout << GT2;
    return 0;
}