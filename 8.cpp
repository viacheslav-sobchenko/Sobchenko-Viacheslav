#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;


vector<vector<vector<int>>> buildAdj(vector<vector<int>> &edges, int V) {
    vector<vector<vector<int>>> adj(V);
    for (auto e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}


void dijkstra(int V, vector<vector<int>> &edges, int src, vector<int> &dist, vector<int> &parent) {
    vector<vector<vector<int>>> adj = buildAdj(edges, V);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top()[1];
        pq.pop();

        for (auto x : adj[u]) {
            int v = x[0];
            int w = x[1];

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}


vector<int> getPath(int t, vector<int> &parent) {
    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = parent[t];
    }
    reverse(path.begin(), path.end());
    return path;
}


int main() {
    int V = 6;
    int src = 0;
    // u - початок , v - кінець , w - вага між ними
    vector<vector<int>> edges = {
        {0,1,1},  {0,1,3},  {0,2,7},
        {1,2,1},  {1,2,2},  {1,5,1},
        {2,3,2},  {2,4,4},  {2,4,1},
        {3,4,1},  {3,5,2},  {3,5,5},
        {5,4,3}
    };

    vector<int> dist, parent;
    dijkstra(V, edges, src, dist, parent);

    cout << "Найкоротші шляхи від вершини 1:\n";
    for (int i = 0; i < V; i++) {
        cout << "До вершини " << i + 1 << ": ";
        if (dist[i] == INT_MAX) {
            cout << "недосяжно\n";
            continue;
        }
        cout << "довжина = " << dist[i] << ", шлях: ";
        vector<int> path = getPath(i, parent);
        for (int j = 0; j < path.size(); j++) {
            cout << path[j] + 1;
            if (j < path.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    return 0;
}
