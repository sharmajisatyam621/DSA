class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int x:nums){
            mp[x]+=1;
            if(mp.find(x)!=mp.end() && mp[x]!=1) return true;
        }

        return false;
    }
};