#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[100000];

int dig(int num, int digit) {
    while(digit--) {
        num /= 10;
    }
    return num % 10;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<6; i++) {
        vector<vector<int>> vec(10);
        for(int p=0; p<n; p++) {
            vec[dig(arr[p], i)].emplace_back(arr[p]);
        }
        int arr_p = 0;
        for(int p=0; p<10; p++) {
            for(int k : vec[p]) {
                arr[arr_p] = k;
                arr_p++;
            }
        }
        if(vec[0].size() == n) break;
    }

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}
