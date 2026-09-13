class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < s.length(); i++){
            sum1 += s[i];
        }
        for(int j = 0; j < t.length(); j++){
            sum2 += t[j];
        }
        return sum2 - sum1;
    }
};