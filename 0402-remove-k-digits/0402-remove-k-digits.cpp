class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.length()){
            return "0";
        }
        stack<char> digits;
        
        for(int i=0;i<num.length();i++){
            while(!digits.empty() && k>0 && digits.top()>num[i]){
                digits.pop();
                k--;
            }
            digits.push(num[i]);
        }
        while(k>0){
            digits.pop();
            k--;
        }
        string res;
        while(!digits.empty()){
            res.push_back(digits.top());
            digits.pop();
        }
        reverse(res.begin(),res.end());

        int i=0;

        while(i<res.size() && res[i]=='0'){
            i++;
        }

        res=res.substr(i);

        return res.empty()? "0": res;
    }
};