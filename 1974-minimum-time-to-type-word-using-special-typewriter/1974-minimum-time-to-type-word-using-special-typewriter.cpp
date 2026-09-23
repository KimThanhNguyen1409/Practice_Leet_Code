class Solution {
public:
    int minTimeToType(string word) {
        int minTime = 0;
        char pointer = 'a';
        for(char c : word){
            int dis = abs(c - pointer);
            minTime += min(dis, 26 -dis);
            minTime += 1;
            pointer = c;
        }
        return minTime;
    }
};