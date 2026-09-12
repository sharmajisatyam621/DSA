class Solution {
public:
     struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // [left, right, weight, original_index]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by right endpoint
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        // previous[i] = last interval ending before a[i] starts
        vector<int> previous(n);

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            int pos = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][1] < a[i][0]) {
                    pos = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }

            previous[i] = pos;
        }

        // dp[i][k] = best answer using first i intervals
        // and taking at most k intervals
        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k].score = 0;
            }
        }

        for (int i = 1; i <= n; i++) {

            for (int k = 0; k <= 4; k++) {

                // Don't take current interval
                dp[i][k] = dp[i - 1][k];

                if (k == 0)
                    continue;

                // Take current interval
                int p = previous[i - 1];

                Node take;

                take.score =
                    a[i - 1][2] +
                    dp[p + 1][k - 1].score;

                take.indices =
                    dp[p + 1][k - 1].indices;

                take.indices.push_back(a[i - 1][3]);

                sort(take.indices.begin(), take.indices.end());

                if (better(take, dp[i][k])) {
                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].indices;
    }
};