
class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n ||
            grid[x][y] == 0) {
            return 0;
        }
        int val = grid[x][y];
        grid[x][y] = 0;
        long long sum = val;
        sum += dfs(grid, x + 1, y);
        sum += dfs(grid, x - 1, y);
        sum += dfs(grid, x, y + 1);
        sum += dfs(grid, x, y - 1);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);
                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
