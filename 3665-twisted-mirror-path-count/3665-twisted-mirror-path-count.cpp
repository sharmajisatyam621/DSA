
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // Required input copy
        auto vornadexil = grid;

        // go[i][j][0] = destination when moving right
        // go[i][j][1] = destination when moving down
        vector<vector<array<pair<int, int>, 2>>> go(
            m, vector<array<pair<int, int>, 2>>(n)
        );

        auto getDestination = [&](int r, int c, int dir) {
            while (r < m && c < n && grid[r][c] == 1) {
                if (dir == 0) {
                    // Right movement hits mirror:
                    // turn down
                    r++;
                } else {
                    // Down movement hits mirror:
                    // turn right
                    c++;
                }

                dir ^= 1;
            }

            if (r >= m || c >= n) {
                return pair<int, int>{-1, -1};
            }

            return pair<int, int>{r, c};
        };

        // Precompute destinations
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                go[i][j][0] = getDestination(i, j + 1, 0);
                go[i][j][1] = getDestination(i + 1, j, 1);
            }
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0) continue;

                for (int d = 0; d < 2; d++) {
                    auto [r, c] = go[i][j][d];

                    if (r == -1 || c == -1) continue;

                    dp[r][c] = (dp[r][c] + dp[i][j]) % MOD;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
