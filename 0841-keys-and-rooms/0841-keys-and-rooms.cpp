class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        int opened = 1;
        while(!q.empty()){
            int curr_key = q.front();
            q.pop();
            for(int keys : rooms[curr_key]){
                if(!visited[keys]){
                    visited[keys] = true;
                    q.push(keys);
                    opened++;
                }
            }
        }
        return opened == n;
    }
};