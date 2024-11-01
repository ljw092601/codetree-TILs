#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cal_min_space(const vector<int>& vec) {
    int min_space = 20;
    int space = 0;
    int start = 0;
    for (int v:vec) {
        if (v == 1) break;
        start++;
    }
    for (int i=start+1; i<vec.size(); i++) {
        if (vec[i] == 0) space++;
        else {
            if(min_space > space) min_space = space;
            space = 0;
        }
    }
    return min_space+1;
}

int main() {
    int n;
    cin >> n;
    string seat;
    cin >> seat;
    vector<int> vec;
    for (char c:seat) {
        vec.push_back(c-'0');
    }

    int max_seat = 0;
    for (int i=0; i<n; i++) {
        if (vec[i] == 1);
        else {
            vec[i] = 1;
            int se = cal_min_space(vec);
            if (max_seat < se) max_seat = se;
            vec[i] = 0;
        }
    }

    cout << max_seat;
    return 0;
}