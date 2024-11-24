#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int even = 0;
    int odd = 0;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a%2 == 0) even++;
        else odd++;
    }
    while(even < odd + 1) {
        odd -= 2;
        even += 1;
    }
    if (even == odd) cout << odd * 2;
    else cout << odd * 2 + 1;
    return 0;
}