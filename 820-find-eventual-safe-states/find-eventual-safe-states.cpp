class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outdegree(n, 0);
        queue<int> q;
        vector<int> result;

        // Step 1: Reverse the graph and calculate outdegrees
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }

        // Step 2: Start with all terminal nodes (outdegree == 0)
        for (int i = 0; i < n; ++i) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process the graph using BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (int neighbor : reverseGraph[node]) {
                outdegree[neighbor]--;
                if (outdegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Sort the result in ascending order
        sort(result.begin(), result.end());
        return result;
    }
};