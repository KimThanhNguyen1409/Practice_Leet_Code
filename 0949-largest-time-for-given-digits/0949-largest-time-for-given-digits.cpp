class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int maxTime = -1;
        sort(arr.begin(), arr.end());
        do{
            int min = arr[2] * 10 + arr[3];
            int hour = arr[0] * 10 + arr[1];
            if(min < 60 && hour < 24){
                int current = hour * 60 + min;
                maxTime = max(maxTime, current);
            }
        }while(next_permutation(arr.begin(), arr.end()));
        if(maxTime == -1)
            return "";
        int m = maxTime % 60;
        int h = maxTime / 60;
        char ans[6];
        sprintf(ans, "%02d:%02d", h, m);
        return string(ans);
    }
};