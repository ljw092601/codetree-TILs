#include <iostream>
#include <vector>
using namespace std;

void search(int x, vector<vector<int>>& edges, vector<bool>& visited, vector<int>& parents) {
    for(int i=0; i<edges[x].size(); i++) {
        int y = edges[x][i];
        if (!visited[y]) {
            visited[y] = true;
            parents[y] = x;
            search(y, edges, visited, parents);
        }
    }
}

int main() {
    int edge_num;
    cin >> edge_num;
    vector<vector<int>> edges(edge_num+1);
    vector<bool> visited(edge_num+1, false);
    vector<int> parents(edge_num+1);

    for(int i=0; i<edge_num-1; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    visited[1] = true;
    search(1, edges, visited, parents);

    for(int i=2; i<edge_num+1; i++) {
        cout << parents[i] << endl;
    }
    return 0;
}