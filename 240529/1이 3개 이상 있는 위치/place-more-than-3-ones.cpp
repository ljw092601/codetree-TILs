#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr_x[4] = {1,0,-1, 0};
    int arr_y[4] = {0,1, 0,-1};
    int n;
    cin >> n;
    vector<vector<int>> double_vec;
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for (int p=0; p<n; p++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        double_vec.push_back(temp);
    }
    int over_3 = 0;
    for (int x=0; x<n; x++) {
        for (int y=0; y<n; y++) {
            int num_1 = 0;
            for(int w=0; w<4; w++) {
                if(0<=x+arr_x[w]&&x+arr_x[w]<n&&0<=y+arr_y[w]&&y+arr_y[w]<n) {
                    if(double_vec[x+arr_x[w]][y+arr_y[w]]) num_1++;
                }
            }
            if (num_1 >= 3) over_3++;
        }
    }
    cout << over_3;
    return 0;
}