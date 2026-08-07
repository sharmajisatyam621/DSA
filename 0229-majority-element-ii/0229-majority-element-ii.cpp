class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> res;
        int n=nums.size();

        int ele1=-1,ele2=-1,cnt1=0,cnt2=0;

        for(int x: nums){
            if(ele1==x){
                cnt1++;
            }
            else if(ele2==x){
                cnt2++;
            }
            else if(cnt1==0){
                ele1=x;
                cnt1++;
            }
            else if(cnt2==0){
                ele2=x;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;

        for(int x: nums){
            if(x==ele1){
                cnt1++;
            }
            if(x==ele2){
                cnt2++;
            }
        }

        if(cnt1>((int)(n/3))) res.emplace_back(ele1);
        if(ele1!=ele2 && cnt2>((int)(n/3))) res.emplace_back(ele2);

        if (res.size()==2 && res[0]>res[1]) swap(res[0],res[1]);

        return res;
        
    }
};