class Solution {
    int MOD = 1e9 + 7;
    vector<long long> sum_val; // Lưu tổng x
    vector<long long> sum_sq;  // Lưu tổng x^2
    vector<long long> lazy;    // Lưu giá trị cần cộng dồn (Lazy)

    // Hàm áp dụng giá trị val vào một node của Segment Tree
    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;
        
        // Theo hằng đẳng thức: (x + val)^2 = x^2 + 2*val*x + val^2
        long long term1 = (2 * val) % MOD;
        term1 = (term1 * sum_val[node]) % MOD;
        long long term2 = ((val * val % MOD) * len) % MOD;
        
        sum_sq[node] = (sum_sq[node] + term1 + term2) % MOD;
        sum_val[node] = (sum_val[node] + (val * len) % MOD) % MOD;
        lazy[node] = (lazy[node] + val) % MOD;
    }

    // Đẩy giá trị lazy xuống các con (Push Down)
    void pushDown(int node, int l, int r) {
        if (lazy[node] != 0 && l != r) {
            int mid = l + (r - l) / 2;
            apply(node * 2, l, mid, lazy[node]);
            apply(node * 2 + 1, mid + 1, r, lazy[node]);
            lazy[node] = 0; // Xóa lazy sau khi đẩy xuống
        }
    }

    // Cập nhật khoảng [ql, qr] cộng thêm val
    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }
        pushDown(node, l, r);
        
        int mid = l + (r - l) / 2;
        if (ql <= mid) update(node * 2, l, mid, ql, qr, val);
        if (qr > mid)  update(node * 2 + 1, mid + 1, r, ql, qr, val);
        
        // Cập nhật lại giá trị của node hiện tại từ 2 node con
        sum_val[node] = (sum_val[node * 2] + sum_val[node * 2 + 1]) % MOD;
        sum_sq[node] = (sum_sq[node * 2] + sum_sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        // Khởi tạo Segment Tree với kích thước 4*N
        sum_val.assign(4 * n + 1, 0);
        sum_sq.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);

        unordered_map<int, int> last_pos;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            // Xác định khoảng cần update: từ vị trí ngay sau lần xuất hiện trước đó đến i
            int l = last_pos.count(nums[i]) ? last_pos[nums[i]] + 1 : 0;
            int r = i;
            
            // Cập nhật đoạn [l, r] tăng thêm 1
            update(1, 0, n - 1, l, r, 1);
            
            // Lấy tổng bình phương của toàn bộ mảng tính đến thời điểm hiện tại cộng vào kết quả
            ans = (ans + sum_sq[1]) % MOD;
            
            // Cập nhật lại vị trí xuất hiện cuối cùng của nums[i]
            last_pos[nums[i]] = i;
        }

        return ans;
    }
};