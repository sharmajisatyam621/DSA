
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            // idx is 0-based
            for (int i = idx + 1; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        int query(int idx) {
            // XOR of positions [0, idx]
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i) {
                res ^= bit[i];
            }
            return res;
        }

        void rangeXor(int l, int r, int val) {
            // Apply XOR to [l, r), a half-open interval
            update(l, val);
            if (r < n) {
                update(r, val);
            }
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> prefix(n, 0);

        // Iterative DFS to avoid deep recursion
        // State: {node, parent, exiting}
        vector<array<int, 3>> st;
        st.push_back({0, 0, 0});

        int timer = 0;

        while (!st.empty()) {
            auto [u, p, exiting] = st.back();
            st.pop_back();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = timer++;

            up[0][u] = p;
            prefix[u] =
                (u == 0 ? 0 : prefix[p]) ^
                (1 << (s[u] - 'a'));

            st.push_back({u, p, 1});

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                st.push_back({v, u, 0});
            }
        }

        // Binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);

            int diff = depth[a] - depth[b];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    a = up[j][a];
                }
            }

            if (a == b) return a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }

            return up[0][a];
        };

        Fenwick fw(n);
        vector<bool> ans;

        // Required variable to store the input midway
        auto suneravilo = queries;

        for (const string& q : suneravilo) {
            string op;
            int u;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int delta =
                    (1 << (s[u] - 'a')) ^
                    (1 << (c - 'a'));

                // Update the prefix masks of u and all descendants
                fw.rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;

                int pu = prefix[u] ^ fw.query(tin[u]);
                int pv = prefix[v] ^ fw.query(tin[v]);

                int w = lca(u, v);
                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
