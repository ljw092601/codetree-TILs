#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> people;

void kill() {
    for(int i=0; i<K-1; i++) {
        people.push(people.front());
        people.pop();
    }
    cout << people.front() << ' ';
    people.pop();
}

int main() {
    cin >> N >> K;

    for(int i=1; i<=N; i++) people.push(i);

    while(!people.empty()) kill();

    return 0;
}
