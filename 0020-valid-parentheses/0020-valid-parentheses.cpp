class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return false;
        stack<char> mySt;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                mySt.push(s[i]);
            }else{
                if(mySt.empty()){
                    return false;
                }else{
                    char c = mySt.top();
                    if(c != '(' && s[i] == ')' || c != '{' && s[i] == '}' || c != '[' && s[i] == ']'){
                        return false;
                    }      
                    mySt.pop();
                }
            }
        }
        return mySt.empty();
    }
};