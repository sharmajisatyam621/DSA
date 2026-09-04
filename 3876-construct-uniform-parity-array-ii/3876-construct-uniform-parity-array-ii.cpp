class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd=INT_MAX;

        for(int x:nums1){
            if(x%2==1){
                minodd=min(minodd,x);
            }
        }

        if(minodd==INT_MAX) return true;

        for(int x:nums1){
            if(x%2==0 && x<minodd){
                return false;
            }
        }

        return true;
    }
};