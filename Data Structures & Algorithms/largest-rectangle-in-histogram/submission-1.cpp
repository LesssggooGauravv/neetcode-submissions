class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int height = heights[i];
            int right = i+1;
            while(right<n && heights[right]>=height){
                right++;
            }
            int left = i;
            while(left>=0 && heights[left]>=height){
                left--;
            }
            right--; left++;
            area = max(area, height * (right-left+1));
        }
        return area;
    }
};
