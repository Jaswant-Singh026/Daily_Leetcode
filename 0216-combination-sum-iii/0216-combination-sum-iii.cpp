class Solution {
public:
    void combination(int k, int n, int ind, vector<int> &ds, vector<vector<int>> &ans){
        if(k == 0 && n == 0){
            ans.push_back(ds);
        }
        for(int i = ind; i < 10; i++){
            if(i > n || k<= 0) break;
            ds.push_back(i);
            combination(k - 1, n - i, i + 1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int ind;
        vector<int> ds;
        vector<vector<int>> ans;
        combination(k, n, 1, ds, ans);
        return ans;
    }
};