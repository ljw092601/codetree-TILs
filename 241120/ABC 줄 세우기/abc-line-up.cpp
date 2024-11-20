#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> line(n);
    for(int i=0; i<n; i++) {
        cin >> line[i];
    }
    vector<char> original(n);
    for(int i=0; i<n; i++) {
        original[i] = 'A' + i;
    }

    int diff = 0;
    for(int i=0; i<n; i++) {
        if (line[i] != original[i]) diff++;
    }
    cout << diff - 1;
    return 0;
}