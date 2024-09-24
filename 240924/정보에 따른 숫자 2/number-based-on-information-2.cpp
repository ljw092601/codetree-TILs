#include <iostream>
#include <vector>
using namespace std;

bool in_line(int n) {
    return 0 <= n && n < 1000;
}

int find_near_S(const vector<int> line, int idx) {
    int dist = 0;
    while(true) {
        if (in_line(idx-dist) && line[idx-dist] == 2) return dist;
        if (in_line(idx+dist) && line[idx+dist] == 2) return dist;
        dist++;
    }
}

int find_near_N(const vector<int> line, int idx) {
    int dist = 0;
    while(true) {
        if (in_line(idx-dist) && line[idx-dist] == 1) return dist;
        if (in_line(idx+dist) && line[idx+dist] == 1) return dist;
        dist++;
    }
}

int main() {
    vector<int> line(1000,0);
    int n, a, b;
    cin >> n >> a >> b;
    while(n--) {
        char N_S;
        int idx;
        cin >> N_S >> idx;
        if (N_S == 'N') line[idx] = 1;
        else line[idx] = 2;
    }
    int special = 0;
    for (int i=a; i<=b; i++) {
        if(find_near_S(line, i) <= find_near_N(line, i)) special++;
    }
    cout << special;
    return 0;
}