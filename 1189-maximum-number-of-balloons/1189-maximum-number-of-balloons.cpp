class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> word(5, 0);
        int ans = 0;
        for(char c : text){
            if(c == 'b'){
                word[0]+=1;
            }else if(c == 'a'){
                word[1]+=1;
            }else if(c == 'l'){
                word[2]+=1;
            }else if(c == 'o'){
                word[3]+=1;
            }else if(c == 'n'){
                word[4]+=1;
            }
        }
        int loop = 1;
        while(loop > 0){
            if(word[0] >= 1 && word[1] >=1 && word[2] >=2 && word[3] >=2 && word[4] >=1){
                word[0]-=1;
                word[1]-=1;
                word[2]-=2;
                word[3]-=2;
                word[4]-=1;
                ans += 1;
            }else{
                loop = -1;
            }
        }
        return ans;
    }
};