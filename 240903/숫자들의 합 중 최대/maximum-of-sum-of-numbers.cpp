#include <iostream>
using namespace std;

int get_sum(int n) {
    int sum = 0;
    while(n>0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    int x,y;
    cin >> x >> y;
    int max_sum = 0;
    for(int i=x; i<=y; i++) {
        if(max_sum < get_sum(i)) max_sum = get_sum(i);
    }
    cout << max_sum;
    return 0;
}