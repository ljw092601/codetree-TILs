#include <iostream>

using namespace std;

int n, m, q;
int a[100][100];
int mean[10000];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void shift(int x1, int y1, int x2, int y2) {
    int temp = a[x2][y2];
    for(int i=x2; i>x1; i--) {
        a[i][y2] = a[i-1][y2];
    }
    for(int i=y2; i>y1; i--) {
        a[x1][i] = a[x1][i-1];
    }
    for(int i=x1; i<x2; i++) {
        a[i][y1] = a[i+1][y1];
    }
    for(int i=y1; i<y2; i++) {
        a[x2][i] = a[x2][i+1];
    }
    a[x2][y2-1] = temp;
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int cal_mean(int x, int y) {
    int num = 1;
    int sum = a[x][y];
    for(int i=0; i<4; i++) {
        if(in_range(x+dx[i], y+dy[i])) {
            sum += a[x+dx[i]][y+dy[i]];
            num++;
        }
    }
    return sum / num;
}

void cal_all_mean(int x1, int y1, int x2, int y2) {
    int idx = 0;
    for(int i=x1; i<=x2; i++) {
        for(int p=y1; p<=y2; p++) {
            mean[idx] = cal_mean(i, p);
            idx++;
        }
    }
    idx = 0;
    for(int i=x1; i<=x2; i++) {
        for(int p=y1; p<=y2; p++) {
            a[i][p] = mean[idx];
            idx++;
        }
    }
}

void wind(int x1, int y1, int x2, int y2) {
    shift(x1-1, y1-1, x2-1, y2-1);
    cal_all_mean(x1-1, y1-1, x2-1, y2-1);
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        wind(r1, c1, r2, c2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << ' ';
        cout << endl;
    }


    return 0;
}
