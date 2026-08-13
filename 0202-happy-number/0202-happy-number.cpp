class Solution {
public:
    bool isHappy(int n) {

        set<int> s;
        while(n!=1 && s.find(n) == s.end()){
            s.insert(n);
            int sum=0;
            int temp=n;
            while(temp!=0){
                int last=temp%10;
                sum+=last*last;
                temp/=10;
            }
            n=sum;
        }
        return (n==1);
    }
};