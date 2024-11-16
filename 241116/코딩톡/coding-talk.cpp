#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Message{
    char name;
    int not_read;
};

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<Message> log(m);
    for (int i=0; i<m; i++) {
        cin >> log[i].name >> log[i].not_read;
    }
    if (log[p-1].not_read == 0) return 0;
    vector<char> read_man(n);
    for(int i=0; i<n; i++) {
        read_man[i] = 'A' + i;
    }
    for (int i=p-1; i<m; i++) {
        auto it = find(read_man.begin(), read_man.end(), log[i].name);
        if (it != read_man.end()) {
            read_man.erase(it);
        }
    }
    for (Message m : log) {
        if (m.not_read == log[p-1].not_read && m.name != log[p-1].name) {
            auto it = find(read_man.begin(), read_man.end(), m.name);
            if (it != read_man.end()) {
                read_man.erase(it);
        }
        }
    }

    for (char c : read_man) cout << c << " ";

    return 0;
}