#include <iostream>
#include <vector>
using namespace std;

int main() {
    int bx,by,lx,ly,rx,ry;
    vector<vector<char>> vec;
    for(int i=0; i<10; i++) {
        vector<char> v(10);
        for(int p=0; p<10; p++) {
            cin >> v[p];
            if (v[p] == 'B') {
                bx = i+1;
                by = p+1;
            }
            if (v[p] == 'L') {
                lx = i+1;
                ly = p+1;
            }
            if (v[p] == 'R') {
                rx = i+1;
                ry = p+1;
            }
        }
        vec.emplace_back(v);
    }

    if(bx == lx && lx == rx) cout << abs(ly - by) +1;
    else if(by == ly && ly == ry) cout << abs(lx - bx) +1;
    else cout << abs(ly - by) + abs(lx - bx) -1;

    return 0;
}