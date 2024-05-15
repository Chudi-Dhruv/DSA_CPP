
void solve(Node* root, int k, int &ans, vector<int> prev_path){
    if(!root) return;
    vector<int> path = prev_path;
    path.push_back(root->data);
    
    solve(root->left,k,ans,path);
    solve(root->right,k,ans,path);
    int sum=0;
    for(int i = path.size()-1;i>=0;i--){
        sum+=path[i];
        if(sum == k){
            ans+=1;
        }
    }
    path.pop_back();
}
class Solution{
  public:
    int sumK(Node *root,int k)
    {
        vector<int> path ;
        int ans = 0;
        // cout<<path.back()<<endl;
        solve(root,k,ans,path);
        return ans;
    }
};
