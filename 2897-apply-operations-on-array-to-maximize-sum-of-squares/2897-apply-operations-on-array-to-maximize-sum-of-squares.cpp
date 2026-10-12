class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        constexpr int kMod = 1'000'000'007;
        constexpr int kMaxBit = 30;
        vector<int> count(kMaxBit, 0);

        for (int num : nums) {
            for (int i = 0; i < kMaxBit; ++i) {
                if ((num >> i) & 1) {
                    count[i]++;
                }
            }
        }

        long long ans = 0;
        for (int step = 0; step < k; ++step) {
            long long currNum = 0;
            for (int i = 0; i < kMaxBit; ++i) {
                if (count[i] > 0) {
                    currNum |= (1LL << i);
                    count[i]--;
                }
            }
            ans = (ans + (currNum * currNum) % kMod) % kMod;
        }

        return ans;
    }
};