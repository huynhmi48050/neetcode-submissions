class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if (n < 2) return 0;
        
        int max_val = 0;
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            int h = min(heights[left], heights[right]);
            max_val = max(max_val, h * (right - left));
            
            while (left < right && heights[left] <= h) ++left;
            while (left < right && heights[right] <= h) --right;
        }
        
        return max_val;
    }
};
