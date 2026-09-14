class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        vector<int> charIndex(256, -1);
        int left = 0, max = 0;
        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            if(charIndex[c] >= left){
                left = charIndex[c] + 1;
            }
            charIndex[c] = right;
            int current = right - left + 1;
            if(current > max){
                max = current;
            }
        }
        return max;
    }
};