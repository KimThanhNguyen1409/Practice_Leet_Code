class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> check(26, 0);
        for(int i = 0; i < magazine.length(); i++){
            char c = magazine[i];
            check[c - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            char c = ransomNote[i];
            check[c - 'a']--;
            if(check[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};