
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze,
                    vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        int dirs[5] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nr = r + dirs[k];
                    int nc = c + dirs[k + 1];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        maze[nr][nc] == '+') {
                        continue;
                    }

                    if (nr == 0 || nr == m - 1 ||
                        nc == 0 || nc == n - 1) {
                        return steps + 1;
                    }

                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }

            steps++;
        }

        return -1;
    }
};
