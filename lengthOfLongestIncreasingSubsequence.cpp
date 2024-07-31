int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);

        for (int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    LIS[i] = max(LIS[j]+1,LIS[i]);
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0;i<n;i++){
            ans = max(ans,LIS[i]);
        }
        return ans;
    }
