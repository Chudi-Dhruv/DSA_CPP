
pair<int,int> solve(TreeNode<int> *root){
    if (!root) return {0,0};
    pair<int,int> l_pair, r_pair;
    l_pair = solve(root->left);
    r_pair = solve(root->right);
    
    int included,not_included;
    included = root->data + l_pair.second + r_pair.second;
    not_included = max(l_pair.first,l_pair.second)+ max(r_pair.first,r_pair.second);
    return {included,not_included};
}

int maximumSumOfNodes(TreeNode<int> *root)
{
    pair<int,int> l_pair = solve(root);
    return max(l_pair.first,l_pair.second);
}
