class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {  
        int n = graph.size();
        vector<int> color(n , 0);
        for(int i = 0; i < n; i++){
            if(color[i] == 0){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int j = 0; j < graph[curr].size(); j++){
                        int ne = graph[curr][j];
                        if(color[ne] == 0){
                            color[ne] = -color[curr];
                            q.push(ne);
                        }else if(color[ne] == color[curr]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};