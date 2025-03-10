class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i-(-1)-1 : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n - (-1)-1 : n - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        
        return maxArea;
    }
};