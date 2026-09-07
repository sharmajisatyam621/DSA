class Solution {
public:
    int distinctSubseqII(string s) {
        const int N = s.length();
    const int MOD = 1e9 + 7;

    // dp[i] stores the number of distinct subsequences of s[0...i-1] (including empty string)
    vector<int> dp(N + 1);
    dp[0] = 1;

    // last[x] stores the last seen index of character 'a' + x
    vector<int> last(26, -1);

    for (int i = 0; i < N; i++) {
        int x = s[i] - 'a';

        // Double the previous count
        dp[i + 1] = (dp[i] * 2L) % MOD; 

        // If the character has appeared before, subtract duplicate subsequences
        if (last[x] >= 0) {
            dp[i + 1] = (dp[i + 1] - dp[last[x]] + MOD) % MOD;
        }

        // Update the last seen position of the character
        last[x] = i;
    }

    // Subtract 1 to exclude the empty subsequence
    dp[N]--;
    
    // Final check to handle negative results from subtraction
    if (dp[N] < 0) dp[N] += MOD;

    return dp[N];
    }
};