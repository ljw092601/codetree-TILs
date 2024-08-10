#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;
    vector<vector<int>> match;
    for(int i=0; i<K; i++) {
        vector<int> grade(N, 0);
        for(int p=0; p<N; p++) {
            cin >> grade[p];
        }
        match.emplace_back(grade);
    }

    int pair = 0;
    for(int i=1; i<=N; i++) {
        for(int p=1; p<=N; p++) {
            if (i != p) {
                bool satisfy = true;
                for (auto g : match) {
                    for(auto s : g) {
                        if(s == i) break;
                        if(s == p) {
                            satisfy = false;
                            break;
                        }
                    }
                    if (!satisfy) break;
                }
                if (satisfy) pair++;
            }
        }
    }
    cout << pair;
    return 0;
}