
    int maxProduct(vector<int>& nums) {

        // // this code dint work not because it is wrong but bcoz there is an edge case where the int is not able to hold the ans value so we had to use the double
        // int n = nums.size();
        // int pref = 1;
        // int suf = 1;
        // int ans = INT_MIN;

        // for(int i = 0 ;i<n;i++){
        //     if(pref==0) pref = 1;
        //     if(suf==0) suf = 1;

        //     pref*=nums[i];
        //     suf*=nums[n-1-i];
        //     ans = max(ans,max(pref,suf));
        // }

        // return ans;


        double pref = 1;
        double suf = 1;
        double ans = INT_MIN;
        long long int n = nums.size();

        for(int i=0;i<n;i++){

            pref = pref*nums[i];
            suf= suf*nums[n-i-1];

            ans = max(ans,max(pref,suf));
            if(pref == 0) pref = 1;
            if(suf== 0) suf= 1;
        }
        return ans;
    }
