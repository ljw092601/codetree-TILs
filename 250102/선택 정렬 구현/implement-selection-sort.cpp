#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        int min = arr[i];
        int min_idx = i;
        for(int p=i; p<n; p++) {
            if (arr[p] < min) {
                min = arr[p];
                min_idx = p;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_idx] = temp;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
