class Solution {
public:
    void Subset(vector<int>& nums, vector<int> &ds, vector<vector<int>> &ans, int ind){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        Subset(nums, ds, ans, ind + 1);
        ds.pop_back();
        Subset(nums, ds, ans, ind + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int ind;
        Subset(nums, ds, ans, 0);
        return ans;
    }
};