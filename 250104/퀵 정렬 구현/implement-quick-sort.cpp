#include <iostream>

using namespace std;

int n;
int arr[100000];

void swap(int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int select_pivot(int st, int ed) {
    if(ed - st < 3) return arr[ed];
    int min_idx = (st+ed)/2;
    if(arr[min_idx] > arr[st]) min_idx = st;
    if(arr[min_idx] > arr[ed]) min_idx = ed;
    swap(min_idx, ed);
    return arr[ed];
} 

int partition(int st, int ed) {
    int pivot = select_pivot(st, ed);
    int blue = st;
    for(int i=st; i<ed; i++) {
        if(arr[i] < pivot) {
            swap(blue, i);
            blue++;
        }
    }
    swap(blue, ed);
    return blue;
}

void quick_sort(int st, int ed) {
    if(st < ed) {
        int pos = partition(st, ed);
        quick_sort(st, pos-1);
        quick_sort(pos+1, ed);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(0, n-1);

    for(int i=0; i<n; i++) cout << arr[i] << ' ';

    return 0;
}
