vector<vector<int>> ans(3);
void solve(TreeNode *root){
    if (!root) return;
    ans[1].push_back(root->data); // Pre-order tree traversal
    solve(root->left);
    ans[0].push_back(root->data); // Pre-order tree traversal
    solve(root->right);
    ans[2].push_back(root->data); // Pre-order tree traversal
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    solve(root);
    return ans;
    // Write your code here.
}
