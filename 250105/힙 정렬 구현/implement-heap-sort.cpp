#include <iostream>

using namespace std;

int n;
int arr[100001];

void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void heapify(int h) {
    int max = arr[h];
    int max_i = h;

    if (h*2 <= n && max < arr[h*2]) {
        max = arr[h*2];
        max_i = h*2;
    }

    if (h*2+1 <= n && max < arr[h*2+1]) {
        max = arr[h*2+1];
        max_i = h*2+1;
    }

    if (max_i != h) {
        swap(h, max_i);
        heapify(max_i);
    }
}

void heap_sort() {
    for(int i = n/2; i >= 1; i--) {
        heapify(i);
    }

    while(n > 1) {
        swap(1, n);
        n--;
        heapify(1);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int size = n;

    heap_sort();

    for (int i = 1; i <= size; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}
