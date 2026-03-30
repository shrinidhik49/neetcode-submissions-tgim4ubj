class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int n = heights.size();
        int r = n-1;
        int max_area = 0;
        
        while (l < r){
            int h = min(heights[l],heights[r]);
            int w = r - l;
            int area = h*w;
            max_area = max(area,max_area);
            
            if (heights[l] <= heights[r]){
                l++;
            }
            else {
                r--;
            }
        }

        return max_area;
    }
};
