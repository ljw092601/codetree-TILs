#include <iostream>

using namespace std;

int n;
int arr[100000];
int temp[100000];

void marge(int st, int mid, int ed) {
    int idx = st;
    int i = st;
    int j = mid+1;

    while(i <= mid && j <= ed) {
        if(arr[i] <= arr[j]) {
            temp[idx] = arr[i];
            idx++;
            i++;
        }
        else {
            temp[idx] = arr[j];
            idx++;
            j++;
        }
    }

    while(j <= ed) {
        temp[idx] = arr[j];
        idx++;
        j++;
    }
    while(i <= mid) {
        temp[idx] = arr[i];
        idx++;
        i++;
    }


    for(int k = st; k<=ed; k++) {
        arr[k] = temp[k];
    }
}

void marge_sort(int st, int ed) {
    if(st < ed) {
        int mid = (st + ed) / 2;
        marge_sort(st, mid);
        marge_sort(mid+1, ed);
        marge(st, mid, ed);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    marge_sort(0, n-1);

    for(int i=0; i<n; i++) cout << arr[i] << ' ';

    return 0;
}
