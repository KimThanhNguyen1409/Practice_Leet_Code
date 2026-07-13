class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())
            return false;
        for(int i = 0; i < s.length(); i++){
            if(s == goal)
                return true;
            char c = s[0];
            s.erase(0, 1);
            s.push_back(c);
        }
        return false;
    }
};