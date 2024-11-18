#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> fst(n);
    vector<int> sec(n);
    for(int i=0;i<n;i++) {
        cin >> fst[i] >> sec[i];
    }

    int max_score = 0;
    int score = 0;
    for (int i=0; i<n; i++) {
        if(fst[i] == 1 && sec[i] == 2) score++;
        if(fst[i] == 2 && sec[i] == 3) score++;
        if(fst[i] == 3 && sec[i] == 1) score++;
    }
    if (max_score < score) max_score = score;

    score = 0;
    for (int i=0; i<n; i++) {
        if(fst[i] == 1 && sec[i] == 3) score++;
        if(fst[i] == 3 && sec[i] == 2) score++;
        if(fst[i] == 2 && sec[i] == 1) score++;
    }
    if (max_score < score) max_score = score;

    score = 0;
    for (int i=0; i<n; i++) {
        if(fst[i] == 3 && sec[i] == 2) score++;
        if(fst[i] == 2 && sec[i] == 1) score++;
        if(fst[i] == 1 && sec[i] == 3) score++;
    }
    if (max_score < score) max_score = score;

    cout << max_score;
    return 0;
}