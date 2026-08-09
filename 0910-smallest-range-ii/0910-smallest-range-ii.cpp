class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[n - 1] - nums[0];

        for (int i = 1; i < n; i++) {
          
            int minh = min(nums[0] + k, nums[i] - k);
            int maxh = max(nums[i - 1] + k, nums[n - 1] - k);
            res = min(res, maxh - minh);
        }
        return res;
    }
};