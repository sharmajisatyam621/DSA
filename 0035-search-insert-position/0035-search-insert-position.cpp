class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int mid,i=0,j=n-1;
        while(i<=j){
            mid=i+(j-i)/2;
            if(nums[mid]<target) i=mid+1;
            else if(nums[mid]>target) j=mid-1;
            else return mid;
        }

        return i;
    }
};