#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct researcher {
    bool infect = false;
    int infect_num;
};

struct shake_record {
    int idx;
    int a;
    int b;
};

int main() {
    int n, k, p, t;
    cin >> n >> k >> p >> t;
    researcher base;
    base.infect_num = k;
    vector<researcher> res_vec(n+1, base);
    res_vec[p].infect = true;
    vector<shake_record> shake_vec;
    while(t--) {
        shake_record shake;
        cin >> shake.idx >> shake.a >> shake.b;
        shake_vec.push_back(shake);
    }
    sort(shake_vec.begin(), shake_vec.end(), [](auto a, auto b){return a.idx < b.idx;});
    for (auto record : shake_vec) {
        if (res_vec[record.a].infect && res_vec[record.b].infect) {
            res_vec[record.a].infect_num -= 1;
            res_vec[record.b].infect_num -= 1;
        }
        else if (res_vec[record.a].infect) {
            if(res_vec[record.a].infect_num > 0) {
                res_vec[record.b].infect = true;
                res_vec[record.a].infect_num -= 1;
            }
        }
        else if (res_vec[record.b].infect) {
            if(res_vec[record.b].infect_num > 0) {
                res_vec[record.a].infect = true;
                res_vec[record.b].infect_num -= 1;
            }
        }
        else;
    }
    for (int i=1; i<res_vec.size(); i++) {
        if (res_vec[i].infect) cout << 1;
        else cout << 0;
    }
    return 0;
}