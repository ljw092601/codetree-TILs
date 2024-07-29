#include <iostream>
#include <vector>
using namespace std;

struct Worker {
    int st;
    int ed;
};

int main() {
    int n;
    cin >> n;
    vector<Worker> worker_vec;
    for(int i=0; i<n; i++) {
        int st, ed;
        cin >> st >> ed;
        Worker worker;
        worker.st = st;
        worker.ed = ed;
        worker_vec.emplace_back(worker);
    }
    int max_time = 0;
    for(int i=0; i<n; i++) {
        vector<int> time_vec(1000,0);
        for(int p=0; p<n; p++) {
            if (p != i) {
                for (int k=worker_vec[p].st; k<worker_vec[p].ed; k++) {
                    time_vec[k] = 1;
                }
            }
        }
        int time = 0;
        for(int m : time_vec) {
            if (m) time++;
        }
        if (max_time < time) max_time = time;
    }
    cout << max_time;
    return 0;
}