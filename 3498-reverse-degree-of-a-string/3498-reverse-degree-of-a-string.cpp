class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int val=('z'-s[i]+1)*(i+1);
            sum+=val;
        }

        return sum;
    }
};