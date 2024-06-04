#include <iostream>
using namespace std;

int board[19][19] = {0,}; 

bool row_win(int x, int y) {
    for(int i=0; i<5; i++) {
        if(board[x][y] != board[x][y+i]) return false;
    }
    return true;
}

bool col_win(int x, int y) {
    for(int i=0; i<5; i++) {
        if(board[x][y] != board[x+i][y]) return false;
    }
    return true;
}

bool diag_win_R(int x, int y) {
    for(int i=0; i<5; i++) {
        if(board[x][y] != board[x+i][y+i]) return false;
    }
    return true;
}

bool diag_win_L(int x, int y) {
    for(int i=0; i<5; i++) {
        if(board[x][y] != board[x+i][y-i]) return false;
    }
    return true;
}

int how_win(int x, int y) {
    if(row_win(x,y)) return 1;
    if(col_win(x,y)) return 2;
    if(diag_win_R(x,y)) return 3;
    if(diag_win_L(x,y)) return 4;
    return 0;
}

void win_print() {
    for(int i=0; i<19; i++) {
        for(int p=0; p<19; p++) {
            if(board[i][p]) {
                if(how_win(i,p)) {
                    cout << board[i][p] << endl;
                    if(how_win(i,p) == 1) cout << i+1 << " " << p+3;
                    if(how_win(i,p) == 2) cout << i+3 << " " << p+1;
                    if(how_win(i,p) == 3) cout << i+3 << " " << p+3;
                    if(how_win(i,p) == 4) cout << i+3 << " " << p-1;
                    return;
                }
            } 
        }
    }
    cout << 0;
}

int main() {
    for(int i=0; i<19; i++) {
        for(int p=0; p<19; p++) {
            cin >> board[i][p];
        }
    }
    win_print();
    return 0;
}