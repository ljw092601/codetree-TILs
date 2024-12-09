#include <iostream>
#include <vector>
using namespace std;

void search(int x, vector<vector<int>>& edges, vector<bool>& visited) {
    for(int i=0; i<edges[x].size(); i++) {
        int y = edges[x][i];
        if(!visited[y]) {
            visited[y] = true;
            search(y, edges, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n+1);
    vector<bool> visited(n+1);
    while(m--) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[1] = true;
    search(1, edges, visited);
    int visit_num = 0;
    for(int i=2; i<n+1; i++) {
        if(visited[i]) visit_num++;
    }
    cout << visit_num;

    return 0;
}