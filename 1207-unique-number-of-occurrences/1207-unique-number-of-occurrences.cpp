class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int val=0;

        for(int x : arr){
            mp[x]++;
        }

         unordered_set<int> st;

        // Check frequencies
        for (auto [x, freq] : mp) {
            if (st.count(freq))
                return false;

            st.insert(freq);
        }

        return true;
    }
};