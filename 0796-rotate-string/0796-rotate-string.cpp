class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1 = s+s;
        if (s.length() != goal.length())
        return false;

       return (s1.find(goal) != string::npos);
    }    
};