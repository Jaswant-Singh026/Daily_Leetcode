class Solution {
public:
    int totalDays(vector<int>& nums, int capacity){
        int n = nums.size();
        int days = 1;
        int load = 0;
        for(int i = 0; i < n; i++){
            if((load+nums[i]) > capacity){
                days += 1;
                load = nums[i];
            }
            else{
                load += nums[i];
            } 
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = low + (high - low)/2;
            int reqDays = totalDays(weights, mid);
            if(reqDays <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};