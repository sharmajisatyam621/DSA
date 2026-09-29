class Solution {
public:
    int m, n;
    vector<vector<char>> grid;
    vector<vector<vector<int>>> dp;

    bool dfs(int r, int c, int balance) {

        if (r >= m || c >= n)
            return false;

        if (grid[r][c] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (r == m - 1 && c == n - 1)
            return balance == 0;

        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        bool ans = dfs(r + 1, c, balance) ||
                   dfs(r, c + 1, balance);

        return dp[r][c][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        if (grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')')
            return false;

        this->grid = grid;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return dfs(0, 0, 0);
    }
};