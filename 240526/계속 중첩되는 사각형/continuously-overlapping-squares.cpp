#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> squ_vec(200, vector<int>(200, 0));
    int n,x1,y1,x2,y2;
    cin >> n;
    int nth = 1;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (nth % 2 == 1){
            for (int i=x1; i<x2; i++) {
                for (int p=y1; p<y2; p++) {
                    squ_vec[i+100][p+100] = 0;
                }
            }
        }
        else {
            for (int i=x1; i<x2; i++) {
                for (int p=y1; p<y2; p++) {
                    squ_vec[i+100][p+100] = 1;
                }
            }
        }
        nth++;
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