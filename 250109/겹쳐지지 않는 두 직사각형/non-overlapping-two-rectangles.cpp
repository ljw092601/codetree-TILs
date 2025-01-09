#include <iostream>
#include <climits>
using namespace std;

int n, m;
int grid[5][5];
int max_sum = -INT_MAX;

int cal_sum(int x, int y, int h, int w) {
    int sum = 0;
    for(int i=x; i<=h; i++) {
        for(int p=y; p<=w; p++) {
            sum += grid[i][p];
        }
    }
    return sum;
}

void cal_max(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2) {
    max_sum = max(max_sum, cal_sum(x1,y1,h1,w1) + cal_sum(x2,y2,h2,w2));
}

bool is_over(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2) {
    return (x1 <= x2 && x2 <= h1 && y1 <= y2 && y2 <= w1) || (x2 <= x1 && x1 <= h2 && y2 <= y1 && y1 <= w2);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int p=0; p<m; p++) {
            for(int k=i; k<n; k++) {
                for(int j=p; j<m; j++) {
                    for(int i2=i; i2<n; i2++) {
                        for(int p2=p; p2<m; p2++) {
                            for(int k2=i2; k2<n; k2++) {
                                for(int j2=p2; j2<m; j2++) {
                                    if(!is_over(i,p,k,j,i2,p2,k2,j2)) {
                                        cal_max(i,p,k,j,i2,p2,k2,j2);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max_sum;

    return 0;
}
