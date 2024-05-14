/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

pair<int,bool> isBalancedBT_pair(TreeNode<int>* root){
    // Write your code here.
    if (root == NULL) {
        pair<int,bool> p=make_pair(0,true);
        return p;
    }

    pair<int,bool> p,left,right;
    left = isBalancedBT_pair(root->left);
    right = isBalancedBT_pair(root->right);
    int l =left.first;
    int r = right.first;
    p.first = max(l,r)+1;



    if(left.second&&
    right.second&&
    abs(l-r)<=1){
        p.second = true;

    }
    else p.second = false;
    return p;
}
bool isBalancedBT(TreeNode<int>* root){
    return isBalancedBT_pair(root).second;
}
