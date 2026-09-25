class Solution {
public:

    set<string> parse(string &s, int &i) {

        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++; // skip '{'

                set<string> inside = parse(s, i);

                i++; // skip '}'

                result = multiply(result, inside);

            }
            else if (s[i] == ',') {

                i++; // skip ','

                set<string> right = parse(s, i);

                result.insert(right.begin(), right.end());

                break;
            }
            else {

                // Normal character
                set<string> cur;
                cur.insert(string(1, s[i]));

                result = multiply(result, cur);

                i++;
            }
        }

        return result;
    }

    set<string> multiply(set<string>& A, set<string>& B) {

        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};