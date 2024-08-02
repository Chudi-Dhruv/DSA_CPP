int solve(vector<int> &values, vector<int> &weights, int i, int w){
	if (i == 0){
		if (weights[0]<=w){
			return values[0];
			}
		else return 0;	
	}
	int take = 0;
	int nottake = 0;
	if (weights[i]<=w)
		take = values[i]+solve(values, weights, i-1, w - weights[i]);
	nottake = 0 +solve(values, weights, i-1, w);
	int ans = max(take,nottake);
	return ans;
}

int solveMem(vector<int> &values, vector<int> &weights, int i, int w, vector<vector<int>> &dp){
	if (i == 0){
		if (weights[0]<=w){
			return values[0];
			}
		else return 0;	
	}
	if (dp[i][w] != -1){
		return dp[i][w];
	}
	int take = 0;
	int nottake = 0;
	if (weights[i]<=w)
		take = values[i]+solveMem(values, weights, i-1, w - weights[i],dp);
	nottake = 0 +solveMem(values, weights, i-1, w, dp);
	dp[i][w] = max(take,nottake);
	
	return dp[i][w];
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>((w+1),-1));
	return solveMem(values,weights, n-1 ,w, dp);
	// return solve(values,weights, n-1 ,w);
	// Write your code here
}
