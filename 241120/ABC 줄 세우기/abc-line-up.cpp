#include <iostream>
#include <vector>
using namespace std;

bool same(const vector<char> v1, const vector<char> v2, int n) {
    for(int i=0; i<n; i++) {
        if(v1[i] != v2[i]) return false;
    }
    return true;
}

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

    

    return 0;
}