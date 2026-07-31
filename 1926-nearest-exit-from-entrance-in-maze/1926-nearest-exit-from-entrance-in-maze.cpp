class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        int dirX[] = {-1, 1, 0, 0};
        int dirY[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            
            int r = curr[0];
            int c = curr[1];
            int step = curr[2];
            if((r != entrance[0] || c != entrance[1]) && 
               (r == 0 || c == 0 || r == m - 1 || c == n - 1)){
                return step;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dirX[i];
                int nc = c + dirY[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.'){
                    maze[nr][nc] = '+'; 
                    q.push({nr, nc, step + 1});
                }
            }
        }
        return -1; 
    }
};