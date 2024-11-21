#include <iostream>
#include <vector>
using namespace std;

int go_to(vector<char>& v, int from, int to) {
    int temp = v[from];
    int mov = 0;
    for(int i = from; i>to; i--) {
        v[i] = v[i-1];
        mov++;
    }
    v[to] = temp;
    return mov;
}

int main() {
    int n;
    cin >> n;
    vector<char> line(n);
    for(int i=0; i<n; i++) {
        cin >> line[i];
    }
    int mov_cnt = 0;
    for(int i=0; i<n; i++) {
        char obj = 'A' + i;
        int idx;
        for(int p=0; p<n; p++) {
            if (line[p] == obj) {
                idx = p;
                break;
            }
        }
        if(idx != i) {
            mov_cnt += go_to(line, idx, i);
        }
    }
    cout << mov_cnt;
    

    return 0;
}