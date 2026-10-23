class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != i)
                k &= nums[i];
        }
        return max(k, 0);
    }
};