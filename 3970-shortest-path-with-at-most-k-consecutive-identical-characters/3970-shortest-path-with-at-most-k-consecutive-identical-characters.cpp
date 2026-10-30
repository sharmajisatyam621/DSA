
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
        }

        // dist[node][consecutive count]
        vector<vector<int>> dist(
            n, vector<int>(k + 1, INT_MAX)
        );

        // {distance, node, consecutive count}
        using State = tuple<int, int, int>;

        priority_queue<
            State,
            vector<State>,
            greater<State>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            // Ignore outdated states
            if (d != dist[u][cnt]) {
                continue;
            }

            if (u == n - 1) {
                return d;
            }

            for (auto [v, w] : adj[u]) {

                int newCount;

                if (labels[u] == labels[v]) {
                    newCount = cnt + 1;
                } else {
                    newCount = 1;
                }

                if (newCount > k) {
                    continue;
                }

                int newDist = d + w;

                if (newDist < dist[v][newCount]) {
                    dist[v][newCount] = newDist;

                    pq.push({
                        newDist,
                        v,
                        newCount
                    });
                }
            }
        }

        return -1;
    }
};
