class Solution {

bool binarysearch (vector<int> &matrix, int target) {
    int l = 0;
    int r = matrix.size() - 1;

    while(l <= r) {
        int mid = l + (r-l)/2;
        if (target == matrix[mid]) {
            return true;
        }
        else if (target > matrix[mid]) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    return false;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();


        for (int i =0; i<m ; i++) {
            for (int j=0; j<n;j++) {
                if (matrix[i][0] <= target && target <= matrix[i][n-1]) {
                    return binarysearch(matrix[i], target);
                }
            }
        }

        return false;
    }
};
