class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char ch : num){
            while(k>0 && !st.empty() && st.top() > ch){
                st.pop();
                k--;
            }
            st.push(ch);
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";

        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        while(result.size() != 0 && result.back() == '0'){
            result.pop_back();
        }
        reverse(result.begin(), result.end());

        if(result.empty()) return "0";

        return result;
    }
};