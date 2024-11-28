#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    while(n--) {
        string command;
        cin >> command;
        if (command == "push_back") {
            int p;
            cin >> p;
            vec.push_back(p);
        }
        else if (command == "get") {
            int i;
            cin >> i;
            cout << vec[i-1] << endl;
        }
        else if (command == "pop_back") {
            vec.pop_back();
        }
        else if (command == "size") {
            cout << vec.size() << endl;
        }
        else {
            cout << "error!" << endl;
        }
    }
    return 0;
}