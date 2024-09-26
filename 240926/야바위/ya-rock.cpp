#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Move {
    int a;
    int b;
    int open;
};

int main() {
    vector<Move> move_vec;
    int n;
    cin >> n;
    while(n--) {
        Move move;
        cin >> move.a >> move.b >> move.open;
        move_vec.push_back(move);
    }
    int max_score = 0;
    for (int i=0; i<3; i++) {
        int cups[3] = {0,};
        cups[i] = 1;
        int score = 0;
        for (Move m : move_vec) {
            swap(cups[m.a-1], cups[m.b-1]);
            if (cups[m.open-1] == 1) score++;
        }
        if (max_score < score) max_score = score;
    }
    cout << max_score;
    return 0;
}