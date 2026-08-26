class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,current=0;
        for(int i=0;i<k;i++){
            current+=nums[i];
        }
        int max_val=current;
        for(int i=1;i<n-k+1;i++){
            current=current-nums[i-1]+nums[i+k-1];
            if(current>max_val){
                max_val=current;
            }
        }
        return (double)max_val/k;
    }
};