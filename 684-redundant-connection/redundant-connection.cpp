class Solution {
private:
    vector<int> parent, rank;

    // Find function with path compression
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]); // Path compression
        }
        return parent[node];
    }

    // Union function with union by rank
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU == rootV) return false; // Cycle detected

        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        // Initialize each node as its own parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }

        // Process each edge
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            // If adding this edge creates a cycle, return it
            if (!unite(u, v)) {
                return {u, v};
            }
        }

        return {};
    }
};
