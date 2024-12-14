#include <iostream>
#include <vector>
using namespace std;
int n, m;

bool not_in(int n, vector<int>& v) {
	for(int p : v) {
		if (p == n) return false;
	}
	return true;
}

int main() {
	cin >> n >> m;
	vector<vector<int>> nodes(n+1, vector<int>(n+1, 0));
	for(int i=0; i<m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		nodes[a][b] = d;
		nodes[b][a] = d;
	}
	vector<int> dist(n+1, 1000);
	dist[1] = 0;
	vector<int> path;
	path.emplace_back(1);
	int cur = 1;
	while(cur != 5) {
		for(int i=1; i<n+1; i++) {
			if (nodes[cur][i]) {
				dist[i] = min(dist[i], nodes[cur][i] + dist[cur]);
			}
		}
		int min_d = 2000;
		for(int k=1; k<n+1; k++) {
			if(not_in(k, path) && min_d > dist[k]){
				min_d = dist[k];
				cur = k;
			}
		}
		path.emplace_back(cur);
	}
	cout << dist[5] << endl;
	for(int p : path) cout << p << " ";
	
	return 0;
}