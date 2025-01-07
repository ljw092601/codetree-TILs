#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;

    while(n--) {
        string com;
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
            cout << s.top() << endl;
            s.pop();
        }
    }
    return 0;
}