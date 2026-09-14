class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, max = 0;
        for(int i = 0; i < k; i++){
            sum+=nums[i];
        }
        max = sum;
        for(int j = k; j < nums.size(); j++){
            sum = sum + nums[j] - nums[j - k];
            if(sum > max){
                max = sum;
            }
        }
        return max / k;
    }
};