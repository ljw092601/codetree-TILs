#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    string start;
    cin >> n >> k >> start;
    int size = start.size();
    vector<string> str_vec;
    while(n--) {
        string word;
        cin >> word;
        if (start == word.substr(0, size)) str_vec.push_back(word);
    }
    sort(str_vec.begin(), str_vec.end());
    cout << str_vec[k-1];
    return 0;
}