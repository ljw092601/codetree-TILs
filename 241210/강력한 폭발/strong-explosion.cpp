#include <iostream>
using namespace std;

int n;
int bomb_pos[20][20];
bool explosion_area[20][20] = {false};
int max_area = 0;
int bomb_num = 0;

void init_explosion() {
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            explosion_area[i][p] = false;
        }
    }
}

bool in_range(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void bomb1(int x, int y) {
    for(int i=-2; i<=2; i++) {
        if (in_range(x+i, y)) explosion_area[x+i][y] = true;
    }
}
void bomb2(int x, int y) {
    for(int i=-1; i<=1; i++) {
        if (in_range(x+i, y)) explosion_area[x+i][y] = true;
        if (in_range(x, y+i)) explosion_area[x][y+i] = true;
    }
}
void bomb3(int x, int y) {
    for(int i=-1; i<=1; i++) {
        if (in_range(x+i, y+i)) explosion_area[x+i][y+i] = true;
        if (in_range(x-i, y+i)) explosion_area[x-i][y+i] = true;
    }
}
void bomb(int bomb_type, int x, int y) {
    if (bomb_type == 1) bomb1(x, y);
    if (bomb_type == 2) bomb2(x, y);
    if (bomb_type == 3) bomb3(x, y);
}

int cal_area() {
    int area = 0;
    init_explosion()
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if(bomb_pos[i][p]) bomb(bomb_pos, i, p);
        }
    }
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            if(explosion_area[i][p]) area++;
        }
    }
    return area;
}

void cal_DFS(int a) {
    if(a == bomb_num) {
        int area = cal_area();
        max_area = max(area, max_area);
        return;
    }
    
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int p=0; p<n; p++) {
            cin >> bomb_pos[i][p];
            if(bomb_pos == 1) bomb_num++;
        }
    }
    cal_DFS(1);
    cout << max_area;
    return 0;
}