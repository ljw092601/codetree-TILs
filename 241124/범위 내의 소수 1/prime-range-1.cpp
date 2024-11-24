#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    vector<int> vec;
    if (a == 1) a = 2;
    if (a <= 2) vec.emplace_back(2);
    for(int i=a; i<=b; i++) {
        if(i%2 != 0) vec.emplace_back(i);
    }
    for(int i=3; i*i<=b; i+=2) {
        for(int& v:vec) if(v%i == 0) v = 0;
    }
    int min_pri = 0;
    int sum = 0;
    bool find_min = false;
    for(int v :vec) {
        if (v != 0) {
            if (!find_min) {
                min_pri = v;
                find_min = true;
            }
            sum += v;
        }
    }
    cout << sum << " " << min_pri;
    return 0;
}