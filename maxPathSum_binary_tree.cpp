
int solve(BinaryTreeNode<int> *root,int &maxi){
    if( !root) return 0;
    int l_ans  = max(solve(root->left,maxi),0);
    int r_ans  = max(solve(root->right,maxi),0);

    int max_chain = max(l_ans,r_ans)+root->data;
    maxi = max(maxi, l_ans+r_ans+root->data);
    return max_chain;
}
int maxPathSum(BinaryTreeNode<int> *root)
{
    int maxi = INT_MIN;
    solve(root,maxi);
    return maxi;
    // Write your code here

}
