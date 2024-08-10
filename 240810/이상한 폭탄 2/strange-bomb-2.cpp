#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> boom_vec(N, 0);
    for (int i=0; i<N; i++) {
        cin >> boom_vec[i];
    }
    int max_num_boom = 0;
    for (int i=0; i<N; i++) {
        int num_boom = 0;
        for(int p=i-K; p<=i+K; p++) {
            if (0 <= p && p < N && p != i) {
                if(boom_vec[p] == boom_vec[i]) num_boom = boom_vec[i];
            }
        }
        if (max_num_boom < num_boom) max_num_boom = num_boom;
    }

    cout << ((max_num_boom) ? max_num_boom : -1);
    return 0;
}