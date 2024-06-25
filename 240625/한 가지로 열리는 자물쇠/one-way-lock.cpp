#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int num = 0;
    for (int i=1; i<=n; i++) {
        for (int p=1; p<=n; p++) {
            for (int k=1; k<=n; k++) {
                if (abs(a-i)<=2 || abs(b-p)<=2 || abs(c-k)<=2) num++;
            }
        }
    }
    cout << num;
    return 0; 
}