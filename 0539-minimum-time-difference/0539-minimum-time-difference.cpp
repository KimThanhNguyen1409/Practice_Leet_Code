class Solution {
public:
    int translate(string &time){
        int h, m;
        sscanf(time.c_str(), "%d:%d",&h, &m);
        return h *60 + m;
    }
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() > 1440)
            return 0;
        vector<int> minutes;
        for(int i = 0; i < timePoints.size(); i++){
            minutes.push_back(translate(timePoints[i]));
        }
        sort(minutes.begin(), minutes.end());
        int min = INT_MAX;
        for(int i = 1; i < minutes.size(); i++){
            int a = minutes[i] - minutes[i - 1];
            if(a < min){
                min = a;
            }
        }
        int diff = (1440 - minutes.back()) + minutes.front();
        if(diff < min)
            min = diff;
        return min;
    } 
};