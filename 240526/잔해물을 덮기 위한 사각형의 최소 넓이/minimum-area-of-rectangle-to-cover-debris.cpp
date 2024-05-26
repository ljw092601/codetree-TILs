#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> squ_vec(2000, vector<int>(2000, 0));
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=x1; i<=x2; i++) {
        for (int p=y1; p<=y2; p++) {
            squ_vec[i+1000][p+1000] += 1;
        }
    }
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=x1; i<x2; i++) {
        for (int p=y1; p<y2; p++) {
            squ_vec[i+1000][p+1000] = 0;
        }
    }
    
    int min_x=0, min_y=0, max_x=0, max_y=0;
    for (int i=0; i<2000; i++) {
        for (int p=0; p<2000; p++) {
            if (squ_vec[i][p] != 0) {
                min_x = i;
                break;
            }
        }
        if(min_x != 0) break;
    }
    for (int i=0; i<2000; i++) {
        for (int p=0; p<2000; p++) {
            if (squ_vec[i][p] != 0) {
                max_x = i;
            }
        }
    }
    for (int i=0; i<2000; i++) {
        for (int p=0; p<2000; p++) {
            if (squ_vec[p][i] != 0) {
                min_y = i;
                break;
            }
        }
        if (min_y != 0) break;
    }
    for (int i=0; i<2000; i++) {
        for (int p=0; p<2000; p++) {
            if (squ_vec[p][i] != 0) {
                max_y = i;
            }
        }
    } 
    cout << (max_x - min_x) * (max_y - min_y);
    return 0;
}