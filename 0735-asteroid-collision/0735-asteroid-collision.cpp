class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> cr;
        for(int i = 0; i < asteroids.size(); i++){
            int alive = 1;
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                if(abs(asteroids[i]) > st.top()){
                    st.pop();
                    continue;
                }else if(abs(asteroids[i]) == st.top()){
                    alive = 0;
                    st.pop();
                }else{
                    alive = 0;
                }
                break;
            }
            if(alive == 1){
                st.push(asteroids[i]);
            }
        }
        int n = st.size();
        cr.resize(n);
        for(int i = n - 1; i >= 0; i--){
            cr[i] = st.top();
            st.pop();
        }
        return cr;
    }
};