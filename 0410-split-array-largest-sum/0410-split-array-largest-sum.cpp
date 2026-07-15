class Solution {
public:
    bool canWesplit(vector<int>& nums, int maxSum, int maxSplit){
        int split = 1;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxSum) return false;
            if((nums[i] + curSum) <= maxSum){
                curSum += nums[i];
            }
            else{
                split++;
                curSum = nums[i];
                if(split > maxSplit) return false;
            }
        }
        return split <= maxSplit;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canWesplit(nums, mid, k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};