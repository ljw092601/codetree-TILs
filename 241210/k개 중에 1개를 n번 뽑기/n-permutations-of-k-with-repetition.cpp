#include <string>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    queue<string> q;
    for(int i=1; i<=k; i++) {
        q.push(to_string(i));
    }
    while(!q.empty()) {
        string out = q.front();
        q.pop();
        if (out.size() == n) {
            for(char c : out) cout << c << " ";
            cout << endl;
        }
        else {
            for(int i=1; i<=k; i++) {
                q.push(out + to_string(i));
            }
        }
    }

    return 0;
}