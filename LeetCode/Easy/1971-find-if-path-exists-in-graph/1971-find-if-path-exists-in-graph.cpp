class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            if (curr == destination) {
                return true;
            }

            // Directly get neighbors of curr
            for (int neighbor : adj[curr]) {

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};