class Solution {
public:
    int digitSum(int num){
        int ans = 0;
        abs(num);
        while(num > 0){
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int min = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int sum = digitSum(nums[i]); 
            if(sum == i){
                if(sum < min){
                    min = sum;
                }
            }
        }
        return min == INT_MAX ? -1 : min;
    }
};