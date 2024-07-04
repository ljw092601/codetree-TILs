#include <iostream>
#include <climits>
#include <numeric>
#include <cmath>
using namespace std;

int diff(int a, int b, int c) {
    int max_diff = abs(a-b);
    if(max_diff < abs(b-c)) max_diff = abs(b-c);
    if(max_diff < abs(c-a)) max_diff = abs(c-a);
    return max_diff;
}

int main() {
    int arr[6] = {0,};
    for(int i=0; i<6; i++) {
        cin >> arr[i];
    }
    int min_diff = INT_MAX;
    int all_team = accumulate(begin(arr), end(arr), 0);
    for(int i=0; i<5; i++) {
        for (int p=i+1; p<6; p++) {
            int first_team = arr[i] + arr[p];
            for (int k=0; k<5; k++) {
                for(int t=k+1; t<6; t++) {
                    if(i!=k && i!=t && p!=k && p!=t) {
                        int second_team = arr[k] + arr[t];
                        int third_team = all_team - first_team - second_team;
                        if (min_diff > diff(first_team, second_team, third_team)) min_diff = diff(first_team, second_team, third_team);
                    }
                }
            }
        }
    }
    cout << min_diff;
    return 0;
}