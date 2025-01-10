#include <iostream>
#include <string>

using namespace std;

string A;

void shift() {
    char temp = A[0];

    for(int i=0; i<A.size()-1; i++) {
        A[i] = A[i+1];
    }
    A[A.size()-1] = temp;
}

int main() {
    cin >> A;

    int min_diff = 10;
    int rep = A.size();

    while(rep--) {
        int diff = 1;
        char now = A[0];
        for(char c: A) {
            if(c != now) {
                now = c;
                diff++;
            }
        }
        min_diff = min(min_diff, diff);
        shift();
    }

    cout << (min_diff == 1 ? 3 : min_diff*2);

    return 0;
}
