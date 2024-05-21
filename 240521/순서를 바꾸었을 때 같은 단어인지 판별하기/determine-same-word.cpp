#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    bool is_same = true;
    if (str1.size() != str2.size()) is_same = false;
    else {
        for (int i=0; i<str1.size(); i++) {
            if(str1[i] != str2[i]) is_same = false;
        }
    }
    cout << ((is_same) ? "Yes" : "No");
    return 0;
}