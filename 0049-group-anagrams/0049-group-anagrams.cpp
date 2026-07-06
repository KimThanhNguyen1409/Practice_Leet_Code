class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> MyMap;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++){
            string c = strs[i];
            sort(strs[i].begin(), strs[i].end());
            MyMap[strs[i]].push_back(c);
        }
        for(const auto &[key, value] : MyMap){
            ans.push_back(value);
        }
        return ans;
    }
};