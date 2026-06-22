class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};

        while(!q.empty()) {

            auto [r,c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == 2147483647) {

                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};