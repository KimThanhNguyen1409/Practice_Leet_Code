class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ans(26, 0);
        for(int i = 0; i < magazine.length(); i++){
            char c = magazine[i];
            ans[c - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            char c = ransomNote[i];
            ans[c - 'a']--;
            if( ans[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};