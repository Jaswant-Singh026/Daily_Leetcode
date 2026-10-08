class Solution {
public:
    void combination(vector<int>& candidates, int target, int ind, vector<int> &ds, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            combination(candidates, target-candidates[i], i + 1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int ind;
        vector<int> ds;
        vector<vector<int>> ans;
        combination(candidates, target, 0, ds, ans);
        return ans;
    }
};