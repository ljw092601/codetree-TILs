#include <iostream>

using namespace std;

string s;
string p;

bool same(int si, int pi) {
    return s[si] == p[pi] || p[pi] == '.';
}

int main() {
    cin >> s;
    cin >> p;

    int a = s.size();
    int b = p.size();

    int si = 0;
    int pi = 0;
    while(si < a || pi < b) {
        if(p[pi + 1] == '*') {
            while(same(si, pi) && si < a) {
                si++;
            }
            pi += 2;
        }
        else {
            if(same(si, pi)) {
                si++;
                pi++;
            }
            else {
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";

    return 0;
}
