class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = n-1;
        int max_val = 0;

        while (left < right) {
            int temp = right - left;
            int val = 0;

            if (heights[left] < heights[right]) {
                val = heights[left]* temp;
                max_val = max(max_val, val);
                left ++;
            }
            else {
                val = heights[right]* temp;
                max_val = max(max_val, val);
                right --;
            }
        }
        return max_val;
    }
};
