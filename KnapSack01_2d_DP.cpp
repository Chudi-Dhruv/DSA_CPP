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
int solveTab( vector<int> &weight, vector<int> &value, int n, int capacity ) {
	// create a dp array
	vector<vector<int> > dp(n, vector<int>(capacity+1, 0) );
	// base case analysis
	for( int w = weight[0]; w <= capacity; w++ ){
		if(weight[0] <= capacity )
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}
	
	for( int index = 1; index < n; index++ ) {
		for( int w = 0; w <= capacity; w++ ) {
			int include = 0;
			
			if( weight[index] <= w )
				include = value[index] + dp[index-1][w-weight[index]];
			int exclude = 0 + dp[index-1][w];
			
			dp[index][w] = max( exclude, include );
		}
	}
	return dp[n-1][capacity];
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n,vector<int>((w+1),-1));
	return solveTab(weights,values, n,w);
	// return solveMem(values,weights, n-1 ,w, dp);
	// return solve(values,weights, n-1 ,w);
	// Write your code here
}
