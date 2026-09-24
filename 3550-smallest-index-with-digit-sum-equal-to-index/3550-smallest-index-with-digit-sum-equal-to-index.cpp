class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int sum=0,temp=nums[i],last_digit;
            while(temp>0){
                last_digit=temp%10;
                sum+=last_digit;
                temp/=10;
            }
            if(i==sum) return i;
        }
        return -1;
    }
};