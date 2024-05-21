#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> str_vec;
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        str_vec.push_back(str);
    }
    sort(str_vec.begin(), str_vec.end());
    for (string s : str_vec) {
        cout << s << endl;
    }
    return 0;
}