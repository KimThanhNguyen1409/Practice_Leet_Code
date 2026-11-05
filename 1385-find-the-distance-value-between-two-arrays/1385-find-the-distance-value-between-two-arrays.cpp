class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            vector<int> check;
            for(int j = 0; j < arr2.size(); j++){
                if(abs(arr1[i] - arr2[j]) <= d){
                    break;
                }
                check.push_back(arr2[j]);
            }
            if(check.size() == arr2.size()){
                ans+=1;
            }
        }
        return ans;
    }
};