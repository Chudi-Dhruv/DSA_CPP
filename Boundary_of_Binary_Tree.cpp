vector<int> ans;
void solveleft(TreeNode<int>*root){
    
    if(!root ||( !root->left && !root->right)) return;
    if(root->left || root->right )    ans.push_back(root->data);
    if(root->left) solveleft(root->left);
    else solveleft(root->right);

}
void solve(TreeNode<int>*root){
    
    if(!root) return;
    solve(root->left);
    if(!root->left && !root->right )    ans.push_back(root->data);
    solve(root->right);

}
void solveright(TreeNode<int>*root){
    
   if(!root ||( !root->left && !root->right)) return;
    if(root->right) solveright(root->right);
    else solveright(root->left);
    ans.push_back(root->data);

}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    ans.push_back(root->data);
    solveleft(root->left);
    solve(root->left);
    solve(root->right);
    solveright(root->right);
    return ans;
	// Write your code here.
}
