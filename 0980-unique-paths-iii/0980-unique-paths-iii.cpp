class Solution {
public:
    int paths = 0;
    int emptyCells = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int remain) {
        int m = grid.size(), n = grid[0].size();

        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)
            return;

        if (grid[x][y] == 2) {
            if (remain == 1) paths++;
            return;
        }

        grid[x][y] = -1;

        dfs(grid, x + 1, y, remain - 1);
        dfs(grid, x - 1, y, remain - 1);
        dfs(grid, x, y + 1, remain - 1);
        dfs(grid, x, y - 1, remain - 1);

        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx, sy;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) emptyCells++;
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(grid, sx, sy, emptyCells + 2);
        return paths;
    }
};