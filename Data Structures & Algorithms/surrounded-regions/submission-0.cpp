class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
            }
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O'){
                q.push({0, i});
            }
            if(board[n-1][i] == 'O'){
                q.push({n-1, i});
            }
        }

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vis[r][c] = 1;
            for(int i= 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0  && nc >= 0 && nr < n && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]){
                    q.push({nr,nc});
                }
            }
        }

        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
