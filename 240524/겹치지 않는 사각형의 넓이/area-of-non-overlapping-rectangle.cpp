#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> squ_vec(2000, vector<int>(2000, 0));
    int n,x1,x2,y1,y2;
    n = 2;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=x1; i<x2; i++) {
            for (int p=y1; p<y2; p++) {
                squ_vec[i+1000][p+1000] += 1;
            }
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=x1; i<x2; i++) {
        for (int p=y1; p<y2; p++) {
            squ_vec[i+1000][p+1000] = 0;
        }
    }
    int area = 0;
    for (int i=0; i<2000; i++) {
        for (int p=0; p<2000; p++) {
            if(squ_vec[i][p]) area++;
        }
    }
    cout << area;
    return 0;
}