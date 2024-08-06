
int solve(vector<vector<int>>& grid, int i , int j, vector<vector<int>>& dp){
    if(i==0 && j==0){
        return grid[0][0];

    }
    if (i<0 || j<0) return 500000;
    if (dp[i][j] != -1) return dp[i][j];
    else{

        int up = grid[i][j] + solve(grid, i-1, j, dp);
        int left = grid[i][j] + solve( grid, i, j-1, dp);
        dp[i][j]= min(up, left);
        return dp[i][j];
    }

}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(grid, n-1,m-1, dp);

        // Tabulation
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if (i==0 && j==0) dp[i][j] = grid[i][j];
                else{
                    int down = grid[i][j];
                    if(i>0){
                        down = grid[i][j] + dp[i-1][j];
                    }
                    else{
                        down = 1e9;
                    }
                    int right = grid[i][j];
                    if(j>0){
                        right = grid[i][j]+ dp[i][j-1];
                    }
                    else{
                        right = 1e9;
                    }
                    dp[i][j] = min(down, right);
                }
            }

        }
        return dp[n-1][m-1];


    }
};
