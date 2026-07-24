class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = (m*n) - 1;
        for(int i = 0; i < m; i++){
            while(low <= high){
                int mid = (low + high)/2;
                int row = mid/n, col = mid%n;
                if(matrix[row][col] == target) return true;
                else if(matrix[row][col] > target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};