#include <iostream>
#include <vector>
using namespace std;
static vector<int> vec;

int main() {
    int n,m;
    cin >> n >> m;
    while(n--) {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    while(m--) {
        int sum = 0;
        int st, ed;
        cin >> st >> ed;
        for (st; st<=ed; st++) {
            sum += vec[st-1];
        }
        cout << sum << endl;
    }
    return 0;
}