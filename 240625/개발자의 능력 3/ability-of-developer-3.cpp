#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    int arr[6] = {0,};
    for (int i=0; i<6; i++) {
        cin >> arr[i];  //0,1,2,3,4,5
    }
    int min_diff = INT_MAX;
    int sum = accumulate(begin(arr), end(arr), 0);
    for (int i=0; i<4; i++) {
        for (int j=i+1; j<5; j++) {
            for (int k=0; k<6; k++) {
                int team1 = arr[i] + arr[j] + arr[k];
                int diff = abs(team1 - (sum - team1));
                if (diff < min_diff) min_diff = diff;
            }
        }
    }
    cout << min_diff;
    return 0;
}