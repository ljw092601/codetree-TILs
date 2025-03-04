#include <iostream>

using namespace std;

string s;
string p;

int main() {
    cin >> s;
    cin >> p;

    int a = s.size();
    int b = p.size();

    int si = 0;
    int pi = 0;
    while(si < a && pi < b) {
        if(p[pi] == '*') {
            pi++;
        }
        else if(s[si] == p[pi] || p[pi] == '.') {
            si++;
            pi++;
        }
        else {
            si++;
        }
    }

    cout << (pi == b ? "true" : "false");

    return 0;
}
