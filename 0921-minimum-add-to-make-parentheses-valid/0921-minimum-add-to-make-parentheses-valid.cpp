class Solution {
public:
    int minAddToMakeValid(string s) {
        int debt = 0;
        int pay = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                debt++;
            }else if(s[i] == ')'){
                if(debt > 0){
                    debt--;
                }else{
                    pay++;
                }
            }
        }
        return debt + pay;
    }
};