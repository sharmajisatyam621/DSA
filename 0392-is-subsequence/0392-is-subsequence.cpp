class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.length();
        int m=s.length();

        if(m>n) return 0;
        if(m==0) return 1;

        int z=0;

        for(int i=0;i<n;i++){
            if(t[i]==s[z]) z++;
        }

       return (z==m);

    }
};