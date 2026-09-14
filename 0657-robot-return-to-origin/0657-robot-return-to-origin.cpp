class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'U'){
                x+= 1;
            }else if(moves[i] == 'D'){
                x-= 1;
            }else if(moves[i] == 'L'){
                y+= 1;
            }else if(moves[i] == 'R'){
                y-= 1;
            }
        }
        return (x == 0 && y == 0) ? true : false;
    }
};