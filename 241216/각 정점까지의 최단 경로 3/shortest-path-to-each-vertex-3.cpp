#include <iostream>
using namespace std;

int n, m;
int graph[101][101];
int dist[101];
bool visited[101] = {false,};

int min_idx() {
    int min_v = (int) 1e9;
    int min_i = -1;
    for(int i=1; i<=n; i++) {
        if(!visited[i] && min_v > dist[i]) {
            min_v = dist[i];
            min_i = i;
        }
    }
    return min_i;
}

void fill_dist() {
    for(int i=0; i<=n; i++) {
        dist[i] = (int) 1e9;
    }
}

void find_dist() {
    dist[1] = 0;
    for(int i=0; i<n; i++) {
        int next = min_idx();
        if(next == -1) break;
        visited[next] = true;
        for(int p=1; p<=n; p++) {
            if (graph[next][p]) {
                dist[p] = min(dist[p], dist[next] + graph[next][p]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    while(m--) {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a][b] = d;
    }
    fill_dist();
    find_dist();
    for (int i=2; i<=n; i++) {
        if(dist[i] == (int) 1e9) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}