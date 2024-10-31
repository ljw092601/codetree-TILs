#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Point{
    int x;
    int y;
};

int max_four(int a, int b, int c, int d) {
    int t = a;
    if (t < b) t = b;
    if (t < c) t = c;
    if (t < d) t = d;
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<Point> p_vec(n);
    for (int i=0; i<n; i++) {
        cin >> p_vec[i].x >> p_vec[i].y;
    }
    int max_x = 0;
    int max_y = 0;
    for (Point p : p_vec) {
        if(max_x < p.x) max_x = p.x;
        if(max_y < p.y) max_y = p.y;
    }

    int min_M = INT_MAX;
    for(int i=2; i<max_x; i+=2) {
        for (int p=2; p<max_y; p+=2) {
            int one = 0;
            int two = 0;
            int thr = 0;
            int fur = 0;
            for (Point po : p_vec) {
                if(po.x < i && po.y < p) one++;
                if(po.x > i && po.y < p) two++;
                if(po.x < i && po.y > p) thr++;
                if(po.x > i && po.y > p) fur++;
            }
            int max = max_four(one, two, thr, fur);
            if (min_M > max) min_M = max;
        }
    }
    cout << min_M;
    return 0;
}