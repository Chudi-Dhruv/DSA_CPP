************************************************************/
bool solve(TreeNode<int> *p,TreeNode<int> *q){
    if(p==NULL || q==NULL){
        if(p==q) return true;
        else return false;
    }
    bool l,r;
    if (p->data != q->data) return false;
    l = solve(p->left, q->right);
    r = solve(p->right, q->left);
    return l&&r;
}
bool isSymmetric(TreeNode<int> *root)
{
    // queue<TreeNode<int> *,bool> q1;
    // queue<TreeNode<int> *,bool> q2;
    // q1.push(root,true);
    // q2.push(root,true);
    // while(!q1.empty() && !q2.empty()){

        
    // }
    return solve(root,root);
    // Write your code here
}
