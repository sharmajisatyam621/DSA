class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=-1,cnt=0;
        for(auto x:nums){
            if(ele==x) cnt++;
            else if(cnt==0){
                ele=x;
                cnt++;
            }
            else cnt--;
        }
        return ele;
    }
};