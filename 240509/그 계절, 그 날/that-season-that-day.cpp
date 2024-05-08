#include <iostream>
#include <string>
using namespace std;

bool is_leaf_year(int y) {
    if (y%400 == 0) return true;
    else {
        if (y%100 == 0) return false;
        else {
            if (y%4 == 0) return true;
            else return false;
        }
    }
}

int max_mon(int y, int m) {
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
            break;
        case 2: {
            if (is_leaf_year(y)) return 29;
            else return 28;
            break;
        }
        case 4: case 6: case 9: case 11:
            return 30;
            break;
    }
}

bool is_exist(int y, int m, int d) {
    if (d <= max_mon(y,m)) return true;
    else return false;
}

string season(int m) {
    switch (m) {
        case 3: case 4: case 5: 
            return "Spring";
            break;
        case 6: case 7: case 8:
            return "Summer";
            break;
        case 9: case 10: case 11:
            return "Fall";
            break;
        case 12: case 1: case 2:
            return "Winter";
            break;
    }
}

int main() {
    int Y, M, D;
    cin >> Y >> M >> D;
    if (is_exist(Y, M, D)) cout << season(M);
    else cout << "-1";
    return 0;
}