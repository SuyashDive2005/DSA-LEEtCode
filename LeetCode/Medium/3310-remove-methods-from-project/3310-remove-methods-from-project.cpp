class Solution {
public:
    void dfs(vector<vector<int>>& adj, int currnode, vector<bool>& visited) {
        if (visited[currnode])
            return;

        visited[currnode] = true;

        for (int v : adj[currnode]) {
            if (!visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<int> res;
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        vector<vector<int>> revadj(n);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            revadj[v].push_back(u);
        }
        dfs(adj, k, visited);

        for (int nd = 0; nd < n; nd++) {
            if (!visited[nd])
                continue;

            for (int parent : revadj[nd]) {
                if (!visited[parent]) {
                    vector<int> allmethods;
                    for (int i = 0; i < n; i++) {
                        allmethods.push_back(i);
                    }
                    return allmethods;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                res.push_back(i);
        }
        return res;
    }
};
