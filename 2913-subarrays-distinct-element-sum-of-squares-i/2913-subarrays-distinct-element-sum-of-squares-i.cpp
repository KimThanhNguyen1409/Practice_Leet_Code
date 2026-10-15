class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> MySet;
            for(int j = i; j < nums.size(); j++){
                MySet.insert(nums[j]);
                int count = MySet.size();
                sum += pow(count, 2);
            }
        }
        return sum;
    }
};