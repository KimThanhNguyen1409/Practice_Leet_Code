class Solution {
public:
    string sortString(string s) {
        string ans;
        vector<char> letter(26, 0);
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            letter[c - 'a']++;
        }
        while(!s.empty()){
            for(int i = 0; i < letter.size(); i++){
                if(letter[i] != 0){
                    ans += ('a' + i);
                    letter[i]--;
                    auto it = find(s.begin(), s.end(), 'a' + i);
                    if(it != s.end()){
                        s.erase(it);
                    }
                }
            }
            for(int i = letter.size() - 1; i >= 0; i--){
                if(letter[i] != 0){
                    ans += ('a' + i);
                    letter[i]--;
                    auto it = find(s.begin(), s.end(), 'a' + i);
                    if(it != s.end()){
                        s.erase(it);
                    }
                }
            }
        }
        return ans;
    }
};