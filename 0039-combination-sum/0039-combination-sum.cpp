class Solution {
public:
    void combination(vector<int> &candidates, int target, int ind, vector<int> &ds, vector<vector<int>> &ans){
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }    
         if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            combination(candidates, target-candidates[ind], ind, ds, ans);
            ds.pop_back();
        }
        combination(candidates, target, ind + 1, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int ind;
        vector<int> ds;
        vector<vector<int>> ans;
        combination(candidates, target, 0, ds, ans);
        return ans;
    }
};