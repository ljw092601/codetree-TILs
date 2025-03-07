#include <iostream>

using namespace std;

int n;
int grid[20][20];

int dx[4] = {-1,-1,1,1};
int dy[4] = {1,-1,-1,1};

int max_sum = 0;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=2; i<n; i++) {
        for(int p=1; p<n-1; p++) {
            int min_L = p;
            int min_R = n-p;
            for(int k=1; k<=min_L; k++) {
                for(int t=1; t<=min_R; t++) {
                    if(k + t <= i) {
                        int sum = 0;
                        int x = i;
                        int y = p;
                        for(int q=0; q<t; q++) {
                            sum += grid[x][y];
                            x += dx[0];
                            y += dy[0];
                        }
                        for(int q=0; q<k; q++) {
                            sum += grid[x][y];
                            x += dx[1];
                            y += dy[1];
                        }
                        for(int q=0; q<t; q++) {
                            sum += grid[x][y];
                            x += dx[2];
                            y += dy[2];
                        }
                        for(int q=0; q<k; q++) {
                            sum += grid[x][y];
                            x += dx[3];
                            y += dy[3];
                        }
                        // cout << sum << ' ' << i << ' ' << p << endl;
                        max_sum = max(max_sum, sum);
                    }
                }
            }
        }
    }

    cout << max_sum;

    return 0;
}
