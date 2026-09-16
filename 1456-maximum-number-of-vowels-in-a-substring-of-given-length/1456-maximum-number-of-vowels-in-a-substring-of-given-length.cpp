class Solution {
public:
    bool IsVowel(char ch){
        return (ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u');
    }
    int maxVowels(string s, int k) {
        int n=s.length();
        int max_vowel_letters=0;

        for(int i=0;i<k;i++){
            if(IsVowel(s[i])) max_vowel_letters++;
        }

        int temp=max_vowel_letters;

        for(int i=1;i<=n-k;i++){
            if(IsVowel(s[i-1])) temp--;
            if((i+k-1)<n && IsVowel(s[i+k-1])) temp++;

            max_vowel_letters=max(max_vowel_letters,temp);
        }

        return max_vowel_letters;
    }
};