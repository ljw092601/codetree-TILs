#include <iostream>
#include <vector>
using namespace std;

struct Hori_line {
    int a = -1;
    int b = -1;
    bool operator < (Hori_line l) {
        if(this -> a == l.a) return this->b < l.b;
        return this->a < l.a;
    }
};

int n, m;
Hori_line lines[16];
vector<Hori_line> selected;
int answer[16];
int try_answer[16];

void go_ladder() {
    for(int i=1; i<=m; i++) {
        int idx = i;
        int state = 1;
        while(state <= 15) {
            for(Hori_line l : lines) {
                if(l.a == idx && l.b == state) {
                    idx++;
                }
                else if(l.a+1 == idx && l.b == state) {
                    idx--;
                }
            }
            state++;
        }
        try_answer[idx] = i;
    }
}

void print() {
    for(Hori_line l : selected) cout << l.b << ' ';
    cout << endl;
}

void select(int t) {
    if(t > m) {
        print();
        return;
    }
    selected.emplace_back(lines[t]);
    select(t+1);
    selected.pop_back();
    select(t+1);
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        Hori_line line;
        cin >> line.a >> line.b;
        lines[i] = line;
    }

    //select(1);
    go_ladder();
    for(int i = 1; i <= m; i++) cout << try_answer[i] << ' ';

    return 0;
}
