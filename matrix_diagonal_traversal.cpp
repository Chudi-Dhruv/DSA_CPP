class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        
        int start;
        ans.push_back(mat[0][0]);
        for(int line = 1; line<m+n-1;line++){
            start = max(0,line+1-n);
            if(line%2==0){
                // normal
                for(int j = start; j<min(m, line+1);j++) ans.push_back(mat[line-j][j]);
            }
            else{
                // reverse
                for(int j = min(m, line+1)-1 ; j >= start;j--) ans.push_back(mat[line-j][j]);
            }
        }
        return ans;
        
    }
};
