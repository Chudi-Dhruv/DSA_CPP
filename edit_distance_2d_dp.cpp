int solveMem(string &w1, string &w2, int i1, int i2, vector<vector<int>> &dp){
    if (i1<=-1) return i2+1;
    if (i2<=-1) return i1+1;

    if (dp[i1+1][i2+1] != 0){
        return dp[i1+1][i2+1];
    }

    if(w1[i1]==w2[i2]){
        dp[i1+1][i2+1] = 0+solveMem(w1,w2, i1-1, i2-1, dp);
        return dp[i1+1][i2+1];
    }

    else{
        dp[i1+1][i2+1] = 1+min(solveMem(w1,w2,i1-1,i2,dp),min(solveMem(w1,w2,i1,i2-1,dp), solveMem(w1,w2,i1-1,i2-1,dp)));
    }

    return dp[i1+1][i2+1];
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp((n+1), vector<int>((m+1),0));
        return solveMem(word1, word2, n-1, m-1, dp);        
    }
};
