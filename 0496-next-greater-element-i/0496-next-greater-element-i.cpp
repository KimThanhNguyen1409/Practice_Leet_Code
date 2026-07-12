class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;      
        int find = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int gre_val = 0;
                    for(int k = j; k < nums2.size(); k++){
                        if(nums2[k] > nums2[j]){
                            gre_val = nums2[k];
                            break;
                        }
                    }
                    if( nums2[j] < gre_val){
                        find = gre_val;
                        ans.push_back(find);
                    }else{
                        find = -1;
                        ans.push_back(find);
                    }
                }
            }
        }
        return ans;
    }
};