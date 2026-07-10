class Solution {
public:
    int possible(vector<int>& nums, int divisor){
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            count += (nums[i] + divisor - 1) / divisor;;
        }
        return count;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
       long long n = nums.size();
       int low = 1;
       int high = *max_element(nums.begin(), nums.end());
       while(low <= high){
       int mid = low + (high - low)/2;
       int count = possible(nums, mid);
        if(count <= threshold){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
       }
       return low;
    }
};