#include <cctype>
class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(!ans.empty() && abs(c - ans.back()) == 32){
                ans.pop_back();
            }else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};