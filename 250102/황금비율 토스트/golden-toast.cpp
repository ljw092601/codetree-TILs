#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> toast;
    string s;
    cin >> s;
    for(char c : s) {
        toast.emplace_back(c);
    }
    vector<char>::iterator it = toast.end();
    while(m--) {
        char com;
        cin >> com;
        if (com == 'L') {
            if (it != toast.begin()) it--;
        }
        else if (com == 'R') {
            if (it != toast.end()) it++;
        }
        else if (com == 'D') {
            if (it != toast.end()) toast.erase(it);
        }
        else {
            char alpha;
            cin >> alpha;
            toast.insert(it, alpha);
            it++;
        }
    }
    for(char c : toast) {
        cout << c;
    }
    return 0;
}