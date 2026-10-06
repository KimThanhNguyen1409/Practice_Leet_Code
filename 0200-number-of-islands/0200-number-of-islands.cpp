class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary and water check
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }

        // Mark as visited (sink the land)
        grid[r][c] = '0';

        // Visit all 4 cardinal directions
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int count = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++; // Found a new island
                    dfs(grid, i, j); // Sink the entire island
                }
            }
        }
        return count;
    }
};
