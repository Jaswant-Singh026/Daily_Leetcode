class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i: asteroids){
            if(i > 0){
                st.push(i);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -i){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(i);
                }
                if(!st.empty() && st.top() == -i){
                    st.pop();
                }
            }
        }
        vector<int> result(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};