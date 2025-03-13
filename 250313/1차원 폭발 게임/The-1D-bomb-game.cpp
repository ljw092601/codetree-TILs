#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> blocks;

void gravity() {
    vector<int> temp;
    for(int i : blocks) {
        if(i) temp.push_back(i);
    }
    blocks.clear();
    for(int i : temp) {
        blocks.push_back(i);
    }
}

void print() {
    cout << blocks.size() << endl;
    for(int i : blocks) cout << i << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        blocks.push_back(number);
    }

    bool end = false;
    while(!end) {
        end = true;
        int i=0;
        while(i+m-1<blocks.size()) {
            int seq = 1;
            int find = i+1;
            while(blocks[i] == blocks[find]) {
                find++;
                seq++;
            }
            if(seq >= m) {
                for(int p=i; p<find; p++) {
                    blocks[p] = 0;
                }
                end = false;
            }
            i = find;
        }
        gravity();
    }

    print();

    return 0;
}
