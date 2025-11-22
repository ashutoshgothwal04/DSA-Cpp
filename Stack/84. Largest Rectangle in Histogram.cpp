class Solution {
public:
    vector<int> prevSmall(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            ans[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmall(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            
            ans[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ps = prevSmall(heights);
        vector<int> ns = nextSmall(heights);

        int res = 0;
        
        for(int i = 0; i < n; i++){
            int width = ns[i] - ps[i] - 1;  
            int area = width * heights[i];
            res = max(res, area);
        }
        return res;
    }
};
