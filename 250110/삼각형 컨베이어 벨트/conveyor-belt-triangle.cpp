#include <iostream>

using namespace std;

int n, t;
int l[200];
int r[200];
int d[200];

void move() {
    int l_temp = l[n-1];
    int r_temp = r[n-1];
    int d_temp = d[n-1];
    for(int i=n-1; i>0; i--) {
        l[i] = l[i-1];
        r[i] = r[i-1];
        d[i] = d[i-1];
    }
    l[0] = d_temp;
    r[0] = l_temp;
    d[0] = r_temp;
} 

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> l[i];

    for (int i = 0; i < n; i++) cin >> r[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    int mov_cnt = t%(n*3);

    for(int i=0; i<mov_cnt; i++) move();

    for (int i = 0; i < n; i++) cout << l[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << r[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << d[i] << ' ';

    return 0;
}