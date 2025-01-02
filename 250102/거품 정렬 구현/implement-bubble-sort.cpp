#include <iostream>

using namespace std;

int n;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i=0; i<n-1; i++) {
            if (arr[i] > arr[i+1]) {
                sorted = false;
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
