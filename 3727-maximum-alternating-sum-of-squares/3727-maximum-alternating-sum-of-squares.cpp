class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        for(int i = 0; i < n; i++){
            sq[i] = (long long)nums[i] * nums[i]; 
        }
        sort(sq.rbegin(), sq.rend());
        
        long long max_sum = 0;
        int num_positives = (n + 1) / 2;
        for(int i = 0; i < n; i++){
            if(i < num_positives){
                max_sum += sq[i];
            } else {
                max_sum -= sq[i];
            }
        }
        
        return max_sum;
    }
};