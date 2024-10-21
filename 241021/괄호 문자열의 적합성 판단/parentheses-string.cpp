#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
public:
    Stack() {len = 0;}
    void push(char c) {
        ch_vec.push_back(c);
        len++;
    }
    char pop() {
        char top = ch_vec.back();
        ch_vec.pop_back();
        len--;
        return top;
    }
    int get_len() {return len;}
    bool is_empty() {
        if (len == 0) return true;
        else return false;
    }
private:
    vector<char> ch_vec;
    int len;
};

int main() {
    Stack stack;
    string line;
    cin >> line;
    for (char c : line) {
        if (c == '(') {
            stack.push(c);
        }
        else {
            if (!stack.get_len()) {
                cout << "No";
                return 0;
            }
            else {
                stack.pop();
            }
        }
    }
    if (stack.is_empty()) cout << "Yes";
    else cout << "No";
    return 0;
}