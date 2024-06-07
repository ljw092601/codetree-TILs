#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    char arr[10000] = {'\0',};
    while(n--) {
        int idx;
        char c;
        cin >> idx >> c;
        arr[idx] = c;
    }
    int max_score = 0;
    for(int i=0; i<10000-k+1; i++) {
        int score = 0;
        for(int p=i; p<=i+k; p++) {
            if(arr[p] == 'G') score += 1;
            if(arr[p] == 'H') score += 2;
        }
        if(max_score < score) max_score = score;
    }
    cout << max_score;
    return 0;
}