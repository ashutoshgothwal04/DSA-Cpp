class Solution {
  public:
  
    bool isSafe(int row, int col, vector<vector<int>>& visited, vector<vector<int>>& m, int n) {
        return (row >= 0 && row < n && col >= 0 && col < n &&
                visited[row][col] == 0 && m[row][col] == 1);
    }
  
    void solve(vector<vector<int>>& m, int x, int y, vector<string>& ans, string path, vector<vector<int>>& visited) {
        int n = m.size();
        
        // base case: reached destination
        if (x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }
        
        // mark current cell
        visited[x][y] = 1;
        
        // UP
        if (isSafe(x - 1, y, visited, m, n)) {
            path.push_back('U');
            solve(m, x - 1, y, ans, path, visited);
            path.pop_back(); // backtrack
        }
        
        // DOWN
        if (isSafe(x + 1, y, visited, m, n)) {
            path.push_back('D');
            solve(m, x + 1, y, ans, path, visited);
            path.pop_back();
        }
        
        // RIGHT
        if (isSafe(x, y + 1, visited, m, n)) {
            path.push_back('R');
            solve(m, x, y + 1, ans, path, visited);
            path.pop_back();
        }
        
        // LEFT
        if (isSafe(x, y - 1, visited, m, n)) {
            path.push_back('L');
            solve(m, x, y - 1, ans, path, visited);
            path.pop_back();
        }
        
        // backtrack: unmark visited
        visited[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> ans;
        int n = m.size();
        
        if (m[0][0] == 0) return ans; // start blocked
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        
        solve(m, 0, 0, ans, path, visited);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
