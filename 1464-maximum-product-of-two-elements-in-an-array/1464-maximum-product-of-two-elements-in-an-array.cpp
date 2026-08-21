class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=INT_MIN,sec_largest=INT_MIN;
        for(auto x:nums){
            if(x>largest){
                sec_largest=largest;
                largest=x;
            }
            else if(x>sec_largest){
                sec_largest=x;
            }
        }
        return (largest-1)*(sec_largest-1);
    }
};