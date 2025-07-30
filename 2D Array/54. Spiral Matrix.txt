class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {                
  
        int n = mat.size(); // row 
        int m = mat[0].size();  // col

        int top = 0;
        int down = n-1;
        int right = m-1;
        int left = 0;

        int dir = 0;
        vector<int> ans;
        //  dir = 0: left to right;
        //  dir = 1; top to bottom;
        //  dir = 2; right to left;
        //  dir = 3; bottom to top;

        while(top <= down && left <= right ){

            if(dir == 0){
                // left to right
                // constant : row (top)

                for(int i=left; i<=right; i++){
                    ans.push_back(mat[top][i]);
                }
                top++;
            }
            else if(dir == 1){
                // top to down
                // constant : col (right)

                for(int i=top; i<=down; i++){
                    ans.push_back(mat[i][right]);
                }
                right--;
            }
           else if(dir == 2){
                // right to left
                // constant : row (down)

                for(int i=right; i>=left; i--){
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            else if(dir == 3){
                // down to top
                // constant : col (left)

                for(int i=down; i>=top; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            dir ++;
                if(dir == 4) dir = 0;
        }
        return ans;
    }
};