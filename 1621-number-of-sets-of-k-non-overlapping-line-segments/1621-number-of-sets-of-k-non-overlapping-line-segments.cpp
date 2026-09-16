class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n, 0)
        );

        // 0 segments can always be chosen in 1 way
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }

        for (int segments = 1; segments <= k; segments++) {
            long long sum = 0;

            for (int points = 1; points < n; points++) {

                // Number of ways where the current point
                // becomes the right endpoint.
                sum = (sum + dp[segments - 1][points - 1]) % MOD;

                dp[segments][points] =
                    (dp[segments][points - 1] + sum) % MOD;
            }
        }

        return dp[k][n - 1];
    }
};