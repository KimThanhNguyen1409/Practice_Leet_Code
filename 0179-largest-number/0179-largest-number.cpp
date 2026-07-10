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
        if(str[0] == "0")
            return "0";
        string final_ans = "";
        for(int i = 0; i < str.size(); i++){
            final_ans += str[i];
        }
        return final_ans;
    }
};