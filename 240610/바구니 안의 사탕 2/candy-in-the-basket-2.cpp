#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int basket[100] = {0,};
    while(n--) {
        int cnt, idx;
        cin >> cnt >> idx;
        basket[idx] += cnt;
    }
    int max_candy = 0;
    for(int i=k; i<=100-k; i++) {
        int candy = 0;
        for (int p=i-k; p<=i+k; p++) {
            candy += basket[p];
        }
        if(max_candy < candy) max_candy = candy;
    }
    cout << max_candy;
    return 0;
}