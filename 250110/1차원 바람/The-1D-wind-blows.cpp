#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];

void push_L(int n) {
    int temp = a[n][m-1];
    for(int i=m-1; i>0; i--) {
        a[n][i] = a[n][i-1];
    }
    a[n][0] = temp;
}

void push_R(int n) {
    int temp = a[n][0];
    for(int i=0; i<m-1; i++) {
        a[n][i] = a[n][i+1];
    }
    a[n][m-1] = temp;
}

bool spread(int x, int y) {
    for(int i=0; i<m; i++) {
        if(a[x][i] == a[y][i]) return true;
    }
    return false;
}

void wind(int l, char d) {
    bool push_to_L;
    if(d == 'L') push_to_L = true;
    else push_to_L = false;

    int st = l-1;
    do {
        if(push_to_L) push_L(st);
        else push_R(st);
        push_to_L = !push_to_L;
        st--;
    } while(st >= 0 && spread(st, st+1));
    
    if(d == 'R') push_to_L = true;
    else push_to_L = false;
    st = l;
    while(st < n && spread(st, st-1)) {
        if(push_to_L) push_L(st);
        else push_R(st);
        push_to_L = !push_to_L;
        st++;
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        wind(r, d);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
