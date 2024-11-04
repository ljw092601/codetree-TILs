#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Point> vec(m);
    for (int i=0; i<m; i++) {
        cin >> vec[i].x >> vec[i].y;
    }

    int max_pair = 0;
    for (int i=1; i<=n-1; i++) {
        for (int p=i+1; p<=n; p++) {
            int pair = 0;
            for (Point po : vec) {
                if ((po.x == i && po.y == p) || (po.x == p && po.y == i)) pair++;
            }
            if (max_pair < pair) max_pair = pair;
        }
    }

    cout << max_pair;
    return 0;
}