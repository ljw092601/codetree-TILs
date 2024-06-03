#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board;
    for (int i=0; i<n; i++) {
        vector<char> chess;
        for (int p=0; p<m; p++) {
            char c;
            cin >> c;
            chess.push_back(c);
        }
        board.push_back(chess);
    }
    int possible = 0;
    for (int i=1; i<n-2; i++) {
        for (int p=1; p<m-2; p++) {
            if (board[0][0] != board[i][p]) {
                for(int t=i+1; t<n-1; t++) {
                    for(int r=p+1; r<m-1; r++) {
                        if (board[0][0] == board[t][r] && board[0][0] != board[n-1][m-1]) possible++;
                    }
                }
            }
        }
    }
    cout << possible;
    return 0;
}