#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
    int x;
    int y;
    int num;
};

int calDist(Point p) {
    return abs(p.x) + abs(p.y);
}

bool cmp(Point a, Point b) {
    if (calDist(a) == calDist(b)) return a.num < b.num;
    return calDist(a) < calDist(b);
}

int main() {
    int n;
    cin >> n;
    vector<Point> p_vec;
    for(int i=0; i<n; i++) {
        Point p;
        p.num = i+1;
        cin >> p.x >> p.y;
        p_vec.push_back(p);
    }
    sort(p_vec.begin(), p_vec.end(), cmp);
    for(auto p : p_vec) {
        cout << p.num << endl;
    }
    return 0;
}