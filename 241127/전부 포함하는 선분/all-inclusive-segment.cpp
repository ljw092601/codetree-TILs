#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cal_len(vector<int> st, vector<int> ed,int eli) {
    int min = 100;
    int max = 0;
    for(int i=0; i<st.size(); i++) {
        if (i != eli) {
            if (st[i] < min) min = st[i];
            if (ed[i] > max) max = ed[i];
        }
    }
    return max - min;
}

int main() {
    int n;
    cin >> n;
    vector<int> st(n);
    vector<int> ed(n);
    for(int i=0; i<n; i++) {
        cin >> st[i] >> ed[i];
    }

    int min_idx = 0;
    int max_idx = 0;
    for(int i=0; i<n; i++) {
        if (st[min_idx] > st[i]) min_idx = i;
        if (ed[max_idx] < ed[i]) max_idx = i;
    }

    cout << min(cal_len(st,ed,min_idx), cal_len(st,ed,max_idx));   

    return 0;
}