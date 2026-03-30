class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n-1;
        int res=0;

        int max_right = height[r];
        int max_left = height[l];
        while (l < r){
            if (max_left < max_right) {
                l++;
                max_left = max(max_left,height[l]);
                res += max_left - height[l];
            } else {
                r--;
                max_right = max(max_right, height[r]);
                res += max_right - height[r];
            }
        }

        return res;
        
    }
};
