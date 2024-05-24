#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> squ_vec(200, vector<int>(200, 0));
    int n,x1,y1;
    cin >> n;
    while(n--) {
        cin >> x1 >> y1;
        for (int i=x1; i<x1+8; i++) {
            for (int p=y1; p<y1+8; p++) {
                squ_vec[i+100][p+100] += 1;
            }
        }
    }
    int area = 0;
    for (int i=0; i<200; i++) {
        for (int p=0; p<200; p++) {
            if(squ_vec[i][p]) area++;
        }
    }
    cout << area;
    return 0;
}