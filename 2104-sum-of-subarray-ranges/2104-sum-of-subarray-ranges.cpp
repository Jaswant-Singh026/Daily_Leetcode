class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                sum += 1LL * arr[mid] * (mid - left) * (right - mid);
            }

            st.push(i);
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] < arr[i])) {
                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                sum += 1LL * arr[mid] * (mid - left) * (right - mid);
            }

            st.push(i);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};