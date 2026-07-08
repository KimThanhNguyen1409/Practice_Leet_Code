class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n = temperatures.size();
        ans.resize(n);
        stack<int> cr; 
        for(int i = 0; i < n; i++){
            while(!cr.empty() && temperatures[i] > temperatures[cr.top()]){
                int pre =cr.top();
                cr.pop();
                ans[pre] = i - pre; 
            }
            cr.push(i);
        }
        return ans;
    }
};