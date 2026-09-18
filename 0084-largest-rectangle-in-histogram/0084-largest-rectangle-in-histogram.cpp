class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        long long sum = 0;
        long long area = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >heights[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                sum = 1LL * heights[mid] * (right - left - 1);
                area = max(area, sum);
            }

            if (i < n) {
                st.push(i);
            }
        }
        return area;
    }
};