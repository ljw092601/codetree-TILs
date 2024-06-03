#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> d_vec;
    for (int i=0; i<n; i++) {
        vector<int> temp;
        for (int p=0; p<n; p++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        d_vec.push_back(temp);
    }
    int max_coin = 0;
    for (int i=0; i<n; i++) {
        for (int p=0; p<n-2; p++) {
            int coin = 0;
            for(int v=p; v<p+3; v++) {
                if(d_vec[i][v]) coin++;
            }
            if(max_coin < coin) max_coin = coin;
        }
    }
    cout << max_coin;
    return 0;
}