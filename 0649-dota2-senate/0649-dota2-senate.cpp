class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        queue<int> R;
        queue<int> D;

        // Store positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                R.push(i);
            else
                D.push(i);
        }

        while (!R.empty() && !D.empty()) {

            int r = R.front();
            R.pop();

            int d = D.front();
            D.pop();

            if (r < d) {
                // Radiant bans Dire
                R.push(r + n);
            }
            else {
                // Dire bans Radiant
                D.push(d + n);
            }
        }

        return R.empty() ? "Dire" : "Radiant";
    }
};