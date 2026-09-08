#include<sstream>
class Solution {
public:
    string reverseWords(string s) {
       int i=s.length()-1;
       string res="";

       while (i >= 0) {

        // Skip spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int end = i;
        while(i>=0 && s[i]!=' '){
            i--;
        }

        res+=s.substr(i+1,end-i);

         while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Add space only if another word exists
        if (i >= 0)
            res += ' ';

        // for-loop will decrement i again
       }
    
       return res;
    }
};