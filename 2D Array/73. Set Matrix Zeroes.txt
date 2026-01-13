class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool rowimpact = false;
        bool colImpact = false;

        // check first row
        for(int j = 0; j < m; j++){
            if(mat[0][j] == 0){
                rowimpact = true;
                break;
            }
        }

        // check first column
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 0){
                colImpact = true;
                break;
            }
        }

        // set markers
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 0){
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // zero inner matrix
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }

        // zero first row
        if(rowimpact){
            for(int j = 0; j < m; j++)
                mat[0][j] = 0;
        }

        // zero first column
        if(colImpact){
            for(int i = 0; i < n; i++)
                mat[i][0] = 0;
        }
    }
};
