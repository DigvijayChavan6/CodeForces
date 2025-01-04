#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

const int MAXN = 410;
const int LOG = 20;

struct Edge {
    int u, v, w;
};

vector<pair<int, int>> graph[MAXN];
int parent[MAXN][LOG], maxWeight[MAXN][LOG];
int depth[MAXN];

// DFS to preprocess parent and maxWeight for Binary Lifting
void dfs(int node, int par, int w, int d) {
    parent[node][0] = par;
    maxWeight[node][0] = w;
    depth[node] = d;
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i - 1] != -1) {
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
            maxWeight[node][i] = max(maxWeight[node][i - 1], maxWeight[parent[node][i - 1]][i - 1]);
        }
    }
    for (auto &[adj, weight] : graph[node]) {
        if (adj != par) {
            dfs(adj, node, weight, d + 1);
        }
    }
}

// Find LCA and collect weights along the path
vector<int> collectWeights(int u, int v) {
    vector<int> weights;
    if (depth[u] < depth[v]) swap(u, v);

    // Lift u to the same level as v
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            weights.push_back(maxWeight[u][i]);
            u = parent[u][i];
        }
    }

    if (u == v) return weights;

    // Lift both u and v until their LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            weights.push_back(maxWeight[u][i]);
            weights.push_back(maxWeight[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    // Add the final edge to the LCA
    weights.push_back(maxWeight[u][0]);
    weights.push_back(maxWeight[v][0]);
    return weights;
}

int main() {
    int t = 0;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            for (int j = 0; j < LOG; j++) {
                parent[i][j] = -1;
                maxWeight[i][j] = 0;
            }
        }

        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

        // Sort edges by weight for Kruskal's MST
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
            return a.w > b.w;
        });

        // Build MST
        vector<int> parentMST(n + 1);
        iota(parentMST.begin(), parentMST.end(), 0);

        function<int(int)> find = [&](int u) {
            return parentMST[u] == u ? u : (parentMST[u] = find(parentMST[u]));
        };

        auto unite = [&](int u, int v) {
            parentMST[find(u)] = find(v);
        };

        for (auto &[u, v, w] : edges) {
            if (find(u) != find(v)) {
                unite(u, v);
                graph[u].emplace_back(v, w);
                graph[v].emplace_back(u, w);
            }
        }

        // Preprocess LCA and maxWeight
        dfs(1, -1, 0, 0);

        // Process queries
        while (q--) {
            int a, b, k;
            cin >> a >> b >> k;
            auto weights = collectWeights(a, b);
            sort(weights.rbegin(), weights.rend());
            cout << weights[k - 1] << " ";
        }
        cout << "\n";
    }

    return 0;
}
