class Solution {
public:
    bool isAnagram(string s, string t) {
          if(s.length()!=t.length()) return 0;
        
        unordered_map<char,int> mp;
        
      for(char c:s){
          mp[c]++;
      }
      for(char c:t){
          mp[c]--;
      }
      for(auto [c,freq]:mp){
          if(freq!=0){
              return 0;
          }
      }
      return 1;
    }
};