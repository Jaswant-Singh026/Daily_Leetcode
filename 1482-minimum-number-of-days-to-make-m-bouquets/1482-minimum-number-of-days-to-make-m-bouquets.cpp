class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int count = 0;
        int noOfBq = 0;
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= day){
                count += 1;
            }
            else{
                noOfBq += (count/k);
                count = 0;
            }
        }
        noOfBq += (count/k);
        return noOfBq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       long long n = bloomDay.size();
       int low = *min_element(bloomDay.begin(), bloomDay.end());
       int high = *max_element(bloomDay.begin(), bloomDay.end());
       if (1LL * m * k > n) return -1;
       while(low <= high){
        int mid = low + (high-low)/2;
        if(possible(bloomDay, mid, m, k)){
            high = mid - 1;
        }
        else{           
            low = mid + 1;
        }
       }
       return low;  
    }
};