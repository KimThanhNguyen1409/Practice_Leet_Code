#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    // Tạo struct để dễ quản lý các thuộc tính
    struct Element {
        int sum;      // Tổng chữ số
        int val;      // Giá trị thực tế của số
        int origIdx;  // Vị trí ban đầu
        
        // Định nghĩa luật sắp xếp (Custom Comparator)
        bool operator<(const Element& other) const {
            if (sum != other.sum) {
                return sum < other.sum; // Ưu tiên 1: Tổng chữ số tăng dần
            }
            return val < other.val;     // Ưu tiên 2: Tổng bằng nhau thì giá trị tăng dần
        }
    };

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<Element> arrPos(n);
        for (int i = 0; i < n; ++i) {
            arrPos[i] = {getDigitSum(nums[i]), nums[i], i};
        }

        // Sắp xếp theo luật đã định nghĩa ở trên
        sort(arrPos.begin(), arrPos.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || arrPos[i].origIdx == i) {
                continue;
            }

            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = arrPos[j].origIdx; 
                cycle_size++;
            }

            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};