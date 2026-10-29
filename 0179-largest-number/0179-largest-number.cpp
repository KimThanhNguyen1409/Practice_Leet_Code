class Solution {
public:
    static bool compare (string &a, string &b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(int i = 0; i < nums.size(); i++){
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), compare);
        string ans = "";
        if(str[0] == "0")
            return "0";
        for(int i = 0; i < str.size(); i++){
            ans += str[i];
        }
        return ans;
    }
};