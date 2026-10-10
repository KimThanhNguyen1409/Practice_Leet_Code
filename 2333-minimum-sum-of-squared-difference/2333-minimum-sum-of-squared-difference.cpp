class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
         int n = nums1.size();
    long long total_k = (long long)k1 + k2;
    
    vector<long long> diffs(n);
    long long max_diff = 0;
    long long total_diff_sum = 0;
    
    for (int i = 0; i < n; ++i) {
        diffs[i] = abs(nums1[i] - nums2[i]);
        max_diff = max(max_diff, diffs[i]);
        total_diff_sum += diffs[i];
    }
    if (total_diff_sum <= total_k) return 0;
    long long low = 0, high = max_diff;
    long long target_diff = max_diff;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long operations_needed = 0;
        
        for (long long d : diffs) {
            if (d > mid) {
                operations_needed += (d - mid);
            }
        }
        
        if (operations_needed <= total_k) {
            target_diff = mid;
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    long long actual_ops = 0;
    for (long long d : diffs) {
        if (d > target_diff) actual_ops += (d - target_diff);
    }
    long long rem_k = total_k - actual_ops;
    
    long long min_sum_sq = 0;
    for (long long d : diffs) {
        long long current_val = (d > target_diff) ? target_diff : d;
        
        if (rem_k > 0 && current_val == target_diff) {
            current_val--;
            rem_k--;
        }
        min_sum_sq += current_val * current_val;
    }
    
    return min_sum_sq;

    }
};