#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool abs_cmp(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int num_pos = 0;
    int num_neg = 0;
    for(int i=0; i<n; i++) {
        cin >> vec[i];
        if (vec[i] < 0) num_neg++;
        if (vec[i] > 0) num_pos++;
    }
    bool zero = n - num_neg - num_pos;
    sort(vec.begin(), vec.end(), abs_cmp);
    // 양,음,음 or 양,양,양 => 음수가 2개 이상 or 음수가 1개 이하, 양수가 3개 이상
    if (num_pos >= 3 || num_neg >= 2) { // 양수 가능
        int num = 0;
        int p3 = 1;
        for(int v : vec) {
            if (num == 3) break;
            if (v > 0) {
                p3 *= v;
                num++;
            }
        }
        int num_n = 0;
        int num_p = 0;
        int p1n2 = 1;
        for (int v : vec) {
            if (num_n == 2 && num_p == 1) break;
            if (v > 0 && num_p != 1) {
                p1n2 *= v;
                num_p++;
            }
            if (v < 0 && num_n != 2) {
                p1n2 *= v;
                num_n++;
            }
        }
        cout << max(p3, p1n2);
    }
    else {
        if (zero) {
            cout << 0;
            return 0;
        }
        else {
            int num = 0;
            int n3 = 1;
            for(int v : vec) {
                if (num == 3) break;
                if (v < 0) {
                    p3 *= v;
                    num++;
                }
            }
            int num_n = 0;
            int num_p = 0;
            int p2n1 = 1;
            for (int v : vec) {
                if (num_n == 1 && num_p == 2) break;
                if (v > 0 && num_p != 2) {
                    p1n2 *= v;
                    num_p++;
                }
                if (v < 0 && num_n != 1) {
                    p1n2 *= v;
                    num_n++;
                }
            }
            if (num != 3) cout << p2n1;
            else if (num_p != 2) cout << n3;
            else cout << min(n3, p2n1);
        }
    }
    return 0;
}