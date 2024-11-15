#include <iostream>
#include <vector>
using namespace std;

struct Pigeon {
    int num;
    int state;
};

int main() {
    int n;
    cin >> n;
    int over = 0;
    vector<Pigeon> vec;
    while(n--) {
        Pigeon pigeon;
        cin >> pigeon.num >> pigeon.state;
        bool in_vec = false;
        for (Pigeon& p : vec) {
            if (p.num == pigeon.num) {
                in_vec = true;
                if (p.state != pigeon.state) {
                    over++; 
                    p.state = pigeon.state;
                }
            }
        }
        if (!in_vec) vec.push_back(pigeon);
    }
    cout << over;
    return 0;
}