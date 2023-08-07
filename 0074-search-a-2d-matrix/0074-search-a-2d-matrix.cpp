class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix.front().size();
        int l = 0, r = m * n - 1, ans = -1;
        int el = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int i = mid / m;
            int j = mid % m;

            if (matrix[i][j] <= target) 
                ans = mid, l = mid + 1, el = matrix[i][j];
             else
                r = mid - 1;
             
        }
        if (el != target) return false;
         return ans == -1 ? false : true;

    }
};
