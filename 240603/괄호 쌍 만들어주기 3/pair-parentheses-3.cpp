#include <iostream>
#include <string>
using namespace std;

int main() {
    string pairs;
    cin >> pairs;
    int num = 0;
    for (int i=0; i<pairs.size(); i++) {
        if (pairs[i] == '(') {
            for(int p=i; p<pairs.size(); p++) {
                if(pairs[p] == ')') num++;
            }
        }
    }
    cout << num;
    return 0;
}