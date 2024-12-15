#include <iostream>
#include <vector>
using namespace std;
int n, m;

int main() {
	cin >> n >> m;
	vector<vector<int>> nodes(n+1, vector<int>(n+1, 0));
	for(int i=0; i<m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		nodes[a][b] = d;
		nodes[b][a] = d;
	}
    int st, ed;
    cin >> st >> ed;
	vector<int> dist(n+1, 1000);
    vector<bool> visited(n+1, false);
	vector<int> path;
	dist[st] = 0;
    visited[st] = true;
	path.emplace_back(st);
	int cur = st;
	while(cur != ed) {
		for(int i=1; i<n+1; i++) {
			if (nodes[cur][i]) {
				dist[i] = min(dist[i], nodes[cur][i] + dist[cur]);
			}
		}
		int min_d = 2000;
		for(int k=1; k<n+1; k++) {
			if(!visited[k] && min_d > dist[k]){
				min_d = dist[k];
				cur = k;
                visited[k] = true;
			}
		}
		path.emplace_back(cur);
	}
	cout << dist[ed] << endl;
	for(int p : path) cout << p << " ";
	
	return 0;
}