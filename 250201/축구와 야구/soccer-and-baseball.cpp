#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu {
    int num;
    int s;
    int b;
};

int n;
vector<Stu> soc_sort;
vector<Stu> base_sort;

int is_same_stu() {
    for(int i=0; i<11; i++) {
        for(int p=0; p<9; p++) {
            if(soc_sort[i].num == base_sort[p].num) return base_sort[p].num;
        }
    }
    return 0;
}

int del_s_n_sum(int idx) {
    int sum = 0;
    for(int i=0; i<12; i++) {
        if(i != idx) {
            sum += soc_sort[i].s;
        }
    }
    for(int i=0; i<9; i++) {
        sum += base_sort[i].b;
    }
    return sum;
}

int del_b_n_sum(int idx) {
    int sum = 0;
    for(int i=0; i<11; i++) {
        sum += soc_sort[i].s;
    }
    for(int i=0; i<10; i++) {
        if(i != idx) {
            sum += base_sort[i].b;
        }
    }
    return sum;
}

int cal_sum() {
    int sum = 0;
    for(int i=0; i<11; i++) {
        sum += soc_sort[i].s;
    }
    for(int i=0; i<9; i++) {
        sum += base_sort[i].b;
    }
    return sum;
}

void print() {
    for(Stu s : soc_sort) {
        cout << s.num << " : " << s.s << endl;
    }
    cout << endl;
    for(Stu b : base_sort) {
        cout << b.num << " : " << b.b << endl;
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        Stu temp;
        cin >> temp.s >> temp.b;
        temp.num = i+1;
        soc_sort.emplace_back(temp);
        base_sort.emplace_back(temp);
    }

    sort(soc_sort.begin(), soc_sort.end(), [](Stu a, Stu b){return a.s >= b.s;});
    sort(base_sort.begin(), base_sort.end(), [](Stu a, Stu b){return a.b >= b.b;});

    int same_n;
    while(same_n = is_same_stu()) {
        int s_idx;
        int b_idx;
        for(int i=0; i<11; i++) {
            if(soc_sort[i].num == same_n) {
                s_idx = i;
            }
        }
        for(int i=0; i<9; i++) {
            if(base_sort[i].num == same_n) {
                b_idx = i;
            }
        }
        if (del_s_n_sum(s_idx) > del_b_n_sum(b_idx)) {
            soc_sort.erase(soc_sort.begin() + s_idx);
        }
        else {
            base_sort.erase(base_sort.begin() + b_idx);
        }
    }

    // print();
    cout << cal_sum();


    return 0;
}
