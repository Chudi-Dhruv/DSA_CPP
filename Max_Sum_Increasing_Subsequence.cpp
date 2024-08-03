int maxSumIS(int arr[], int n)  
	{
	    vector<int> msis(n,0);
	    for(int i=0;i<n;i++){
	        msis[i]=arr[i];
	    }
	    
	    for(int i = n-1; i>=0; i--){
	        for(int j = i+1;j<n;j++){
	            if(arr[i]<arr[j]){
	                msis[i] = max(msis[i],msis[j]+arr[i]);
	            }
	        }
	    }
	    
	    int ans = INT_MIN;
	    for(int i=0;i<n;i++){
	        ans = max(ans,msis[i]);
	    }
	    return ans;

	}  
