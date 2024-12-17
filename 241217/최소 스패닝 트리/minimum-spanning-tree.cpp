#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int a;
    int b;
    int dist;
    Edge(int a, int b, int d) : a(a), b(b), dist(d) {}
    bool operator< (Edge other) {
        return this->dist < other.dist;
    }
};

class Set {
    private:
    vector<int> set;
    public:
    Set() {}
    Set(int size) {
        for(int i=0; i<=size; i++) {
            set.emplace_back(i);
        }
    }
    int find(int node) {
        if(set[node] == node) return node;
        return find(set[node]);
    }
    void uni(int a, int b) {
        set[find(a)] = find(b);
    }
    bool is_uni(int a, int b) {
        return find(a) == find(b);
    }
};

class Graph{
    private:
    vector<Edge> edges;
    int node_n;
    friend class MST;
    public:
    Graph(int n) : node_n(n) {}
    Graph(Graph& other) : edges(other.edges){
        node_n = other.node_n;
    }
    void add_edge(Edge e) {
        edges.emplace_back(e);
    }
};

class MST{
    private:
    Graph& graph;
    vector<Edge> mst;
    vector<bool> working;
    Set set;
    public:
    MST(Graph& graph) : graph(graph), set(graph.node_n) {
        working.resize(graph.node_n+1, true);
    }
    void cal() {
        sort(graph.edges.begin(), graph.edges.end());
        for (Edge edge : graph.edges) {
            if(working[edge.a] && working[edge.b] && !set.is_uni(edge.a, edge.b)) {
                mst.emplace_back(edge);
                set.uni(edge.a, edge.b);
            }
            if (mst.size() == graph.node_n - 1) break;
        }
    }
    void breaking (int break_n) {
        working[break_n] = false;
    }
    int cal_mst_dist() {
        int sum = 0;
        for (Edge edge : mst) {
            sum += edge.dist;
        }
        return sum;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n);
    while(m--) {
        int a, b, d;
        cin >> a >> b >> d;
        graph.add_edge(Edge{a,b,d});
    }
    MST spanning_tree(graph);
    spanning_tree.cal();
    cout << spanning_tree.cal_mst_dist();
    return 0;
}