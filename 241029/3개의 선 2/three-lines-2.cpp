#include <iostream>
#include <vector>
using namespace std;

struct Point{
    int x;
    int y;
};

struct Line {
    bool is_xline;
    int val;
};

bool on_line(Point p, Line l) {
    if(l.is_xline && p.x == l.val) return true;
    else if (!l.is_xline && p.y == l.val) return true;
    return false;
}

bool on_lines(Point p, Line l1, Line l2, Line l3) {
    return on_line(p,l1) || on_line(p,l2) || on_line(p,l3);
}

int main() {
    int n;
    cin >> n;
    vector<Point> point_vec (n);
    for (int i=0; i<n; i++) {
        cin >> point_vec[i].x >> point_vec[i].y;
    }
    vector<Line> line_vec (22);
    for (int i=0; i<11; i++) {
        line_vec[i].is_xline = true;
        line_vec[i].val = i;
    }
    for (int i=0; i<11; i++) {
        line_vec[i+11].is_xline = false;
        line_vec[i+11].val = i;
    }
    for (int i=0; i<20; i++) {
        for (int p=i+1; p<21; p++)
            for (int k=p+1; k<22; k++) {
                bool possible = true;
                for (Point po : point_vec) {
                    if (!on_lines(po,line_vec[i], line_vec[p], line_vec[k]))
                        possible = false;
                }
                if (possible) {
                    cout << 1;
                    return 0;
                }
            }
    }
    cout << 0;
    return 0;
}