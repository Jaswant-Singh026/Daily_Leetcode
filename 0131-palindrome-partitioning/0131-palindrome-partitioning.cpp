class Solution {
public:
    bool isPalindrome(string str){
        int st = 0;
        int end = str.size() - 1;

        while(st <= end){
            if(str[st] != str[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }

    void combination(string s, int ind, int n , vector<string> &ds, vector<vector<string>> &ans){
        if(ind == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i < n; i++){
            string str = s.substr(ind, i-ind+1);

            if(isPalindrome(str)){
                ds.push_back(str);
                combination(s, i+1, n, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        int ind = 0;
        int n = s.size();
        combination(s, ind, n, ds, ans);
        return ans;
    }
};