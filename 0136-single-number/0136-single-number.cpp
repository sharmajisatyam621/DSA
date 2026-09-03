class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int digit=0;
        for(int num:nums){
            digit^=num;
        }
        return digit;
    }
};