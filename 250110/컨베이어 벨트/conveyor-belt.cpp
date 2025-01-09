#include <iostream>

using namespace std;

int n, t;
int u[200];
int d[200];

void move() {
    int u_temp = u[n-1];
    int d_temp = d[n-1];
    for(int i=n-1; i>0; i--) {
        u[i] = u[i-1];
        d[i] = d[i-1];
    }
    u[0] = d_temp;
    d[0] = u_temp;

} 

int main() {
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> u[i];

    for (int i = 0; i < n; i++) cin >> d[i];

    int mov_cnt = t%(n*2);

    for(int i=0; i<mov_cnt; i++) move();

    for (int i = 0; i < n; i++) cout << u[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << d[i] << ' ';

    return 0;
}
