class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1'000'000'007;
        vector<int> cnt(31, 0);

        // Count occurrences of each set bit.
        for (int x : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (x & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Construct k numbers greedily.
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};