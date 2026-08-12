class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int max_finding=nums[0];

        for(int i=1;i<nums.size();i++){
            max_finding=max(max_finding+nums[i],nums[i]);
            res=max(res,max_finding);
        }
        return res;
    }
};