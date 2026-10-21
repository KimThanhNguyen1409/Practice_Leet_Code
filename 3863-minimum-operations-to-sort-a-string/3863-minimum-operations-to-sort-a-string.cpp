#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        
        // 1. Đã sắp xếp sẵn
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // 2. Không thể sắp xếp nếu n = 2 và chưa đúng thứ tự
        if (n == 2) {
            return -1;
        }
        
        vector<bool> pref_sorted(n, false), suff_sorted(n, false);
        vector<char> pref_max(n), suff_min(n);
        
        pref_sorted[0] = true;
        pref_max[0] = s[0];
        for (int i = 1; i < n; i++) {
            pref_sorted[i] = pref_sorted[i - 1] && (s[i] >= s[i - 1]);
            pref_max[i] = max(pref_max[i - 1], s[i]);
        }
        
        suff_sorted[n - 1] = true;
        suff_min[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff_sorted[i] = suff_sorted[i + 1] && (s[i] <= s[i + 1]);
            suff_min[i] = min(suff_min[i + 1], s[i]);
        }
        
        // 3. Kiểm tra xem có thể giải quyết trong 1 thao tác không
        for (int k = 1; k < n; k++) {
            if (suff_sorted[k] && pref_max[k - 1] <= s[k]) {
                return 1;
            }
            if (pref_sorted[k - 1] && s[k - 1] <= suff_min[k]) {
                return 1;
            }
        }
        
        // 4. Tìm ký tự min/max và đếm số lần xuất hiện của chúng
        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());
        int count_min = count(s.begin(), s.end(), min_char);
        int count_max = count(s.begin(), s.end(), max_char);
        
        // Chỉ cần 3 thao tác KHI VÀ CHỈ KHI max ở đầu là duy nhất VÀ min ở cuối là duy nhất
        if (s[0] == max_char && count_max == 1 && s[n - 1] == min_char && count_min == 1) {
            return 3;
        }
        
        // Mọi trường hợp còn lại đều có thể giải quyết bằng 2 thao tác (Pref -> Suff hoặc Suff -> Pref)
        return 2;
    }
};