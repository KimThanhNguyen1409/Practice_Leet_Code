class Solution {
public:
    void RotateLeft(vector<int>& nums) {
        int first = nums[0];
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums.back() = first;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = nums[0];
        bool inc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k + i) % n) {
                inc = false;
                break;
            }
        }

        int ans = INT_MAX;

        if (inc) {
            ans = min(ans, (n - k) % n);
            ans = min(ans, k + 2);
        }

        bool dec = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (k - i + n) % n) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int shift = (n - 1 - k + n) % n;
            ans = min(ans, 1 + min(shift, (n - shift) % n));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};