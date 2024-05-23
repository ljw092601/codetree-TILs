#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[200000] = {0,};
    int n;
    cin >> n;
    int start_p = 100000;
    while(n--) {
        int x;
        char LR;
        cin >> x >> LR;
        x--;
        if (LR == 'L') {
            start_p -= x;
            for (int i=start_p; i<=start_p+x; i++) {
                arr[i] = 1;
            }
        }
        else {
            start_p += x;
            for (int i=start_p-x; i<=start_p; i++) {
                arr[i] = 2;
            }
        }
    }
    int white_tile = 0;
    int black_tile = 0;
    for (int t : arr) {
        if (t == 1) white_tile++;
        if (t == 2) black_tile++;
    }
    cout << white_tile << " " << black_tile;
    return 0;
}