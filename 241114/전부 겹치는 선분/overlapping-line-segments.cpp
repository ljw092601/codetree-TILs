#include <vector>
#include <iostream>
using namespace std;

struct line{
    int start;
    int end;
    bool is_in(int n) {
        return start <= n && n <= end;
    }
};

int main() {
    int n;
    cin >> n;
    vector<line> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i].start >> vec[i].end;
    }
    for (int i=1; i<= 100; i++) {
        bool inter = true;
        for(line l : vec) {
            if(!l.is_in(i)){
                inter = false;
                break;
            }
        }
        if (inter) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}