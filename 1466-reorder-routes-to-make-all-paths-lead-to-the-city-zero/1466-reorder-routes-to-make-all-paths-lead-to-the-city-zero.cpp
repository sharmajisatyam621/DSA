
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &road : connections) {
            int a = road[0];
            int b = road[1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }

        vector<bool> visited(n, false);

        return dfs(0, adj, visited);
    }

    int dfs(int city,
            vector<vector<pair<int, int>>>& adj,
            vector<bool>& visited) {
        visited[city] = true;
        int changes = 0;

        for (auto [neighbor, cost] : adj[city]) {
            if (!visited[neighbor]) {
                changes += cost;
                changes += dfs(neighbor, adj, visited);
            }
        }

        return changes;
    }
};
