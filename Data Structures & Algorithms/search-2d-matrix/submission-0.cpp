class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int rowIndex=mid/m;
            int colIndex=mid%m;
            if(matrix[rowIndex][colIndex]==target)return true;
            if(matrix[rowIndex][colIndex]>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};
