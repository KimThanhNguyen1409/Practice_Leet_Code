class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> MyChar(26, 0);
        for(int i = 0; i < magazine.length(); i++){
            char c = magazine[i];
            MyChar[c - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++){
            char c = ransomNote[i];
            MyChar[c - 'a']--;
            if(MyChar[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};