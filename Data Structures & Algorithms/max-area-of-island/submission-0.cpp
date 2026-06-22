class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int &ans) {

        vis[row][col] = 1;
        ans++;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {

            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, ans);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {
                    int ans = 0;
                    dfs(i, j, grid, vis, ans);
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};