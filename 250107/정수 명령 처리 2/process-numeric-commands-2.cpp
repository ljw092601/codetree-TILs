#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<int> s;
    int n;
    cin >> n;

    while(n--) {
        string com;
        cin >> com;
        if (com == "push") {
            int k;
            cin >> k;
            s.push(k);
        }
        else if (com == "size") {
            cout << s.size() << endl;
        }
        else if (com == "empty") {
            cout << s.empty() << endl;
        }
        else if (com == "pop") {
            cout << s.front() << endl;
            s.pop();
        }
        else {
            cout << s.front() << endl;
        }
    }
    return 0;
}