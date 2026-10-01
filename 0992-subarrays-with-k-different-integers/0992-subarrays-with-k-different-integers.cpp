class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int>& nums, int k){
        unordered_map<int, int> mpp;
        int l = 0, r = 0, result = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;

            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            result += r - l + 1;
            r++;
        }
        return result;
    }
};