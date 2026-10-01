class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int>& nums, int k){
        int l = 0, r = 0, result = 0;
        while(r < nums.size()){
            k -= nums[r] % 2;
            while(k < 0){
                k += nums[l] % 2;
                l++;
            }
            result += r - l + 1;
            r++;
        }
        return result;
    }
};