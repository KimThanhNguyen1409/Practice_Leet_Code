class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int ans = min(n, 2); // subarray 1 hoặc 2 phần tử luôn hợp lệ

        // lastSeen[p] = vị trí gần nhất prime p xuất hiện
        vector<int> lastSeen(1000001, -1);

        for (int right = 0; right < n; right++) {
            int x = nums[right];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {
                    if (lastSeen[p] >= left) {
                        left = lastSeen[p] + 1;
                    }
                    while (x % p == 0)
                        x /= p;

                    lastSeen[p] = right;
                }
            }
            if (x > 1) {
                if (lastSeen[x] >= left) {
                    left = lastSeen[x] + 1;
                }
                lastSeen[x] = right;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};