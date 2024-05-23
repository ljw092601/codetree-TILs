#include <iostream>
#include <vector>
using namespace std;

enum Color {white, black, none};

struct Tile {
    int white = 0;
    int black = 0;
    Color tile_color = none;
};

int main() {
    Tile arr[200000];
    Tile zerotile;
    fill_n(arr, 200000, zerotile);
    int n;
    cin >> n;
    int start_p = 100000;
    while(n--) {
        int x;
        char LR;
        cin >> x >> LR;
        x--;
        if (LR == 'L') {
            start_p -= x;
            for (int i=start_p; i<=start_p+x; i++) {
                arr[i].white += 1;
                arr[i].tile_color = white;
            }
        }
        else {
            start_p += x;
             for (int i=start_p-x; i<=start_p; i++) {
                arr[i].black += 1;
                arr[i].tile_color = black;
            }
        }
    }
    int white_tile = 0;
    int black_tile = 0;
    int gray_tile = 0;
    for (Tile t : arr) {
        if (t.white >= 2 && t.black >= 2) gray_tile++;
        else {
            if(t.tile_color == white) white_tile++;
            if(t.tile_color == black) black_tile++;
            else; 
        }
    }
    cout << white_tile << " " << black_tile << " " << gray_tile;
    return 0;
}