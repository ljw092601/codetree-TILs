#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    for(int i=s1-1; i<e1; i++) {
        blocks[i] = 0;
    }

    int temp[100];
    int idx = 0;
    for(int i=0; i<n; i++) {
        if(blocks[i]) {
            temp[idx] = blocks[i];
            idx++;
        }
    }

    n -= e1 - s1 + 1;

    for(int i=s2-1; i<e2; i++) {
        temp[i] = 0;
    }

    idx = 0;
    for(int i=0; i<n; i++) {
        if(temp[i]) {
            blocks[idx] = temp[i];
            idx++;
        }
    }
    
    n -= e2 - s2 + 1;

    cout << n << endl;

    for(int i=0; i<n; i++) {
        cout << blocks[i] << endl;
    }

    return 0;
}
