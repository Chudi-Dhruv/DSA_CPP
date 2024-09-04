class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> temp;
        vector<int> ans;
        int i =0,j=0;
        int n  = nums.size();
        while(j<n){
            while(!temp.empty() && temp.back() < nums[j]){
                temp.pop_back();
            }
            temp.push_back(nums[j]);
            if(j-i+1 == k){
                ans.push_back(temp.front());
                if(temp.front()==nums[i]){
                    temp.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};


