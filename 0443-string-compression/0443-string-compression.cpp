class Solution {
public:
    int compress(vector<char>& chars) {
           int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

            // Write character
            chars[write++] = ch;

            // Write count if > 1
            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};