/************************************************************

Problem statement
You have been given a Binary Tree of distinct integers and two nodes ‘X’ and ‘Y’. You are supposed to return the LCA (Lowest Common Ancestor) of ‘X’ and ‘Y’.



The LCA of ‘X’ and ‘Y’ in the binary tree is the shared ancestor of ‘X’ and ‘Y’ that is located farthest from the root.



Note :
You may assume that given ‘X’ and ‘Y’ definitely exist in the given binary tree.
************************************************************/
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> * solve(TreeNode<int> * root, int x, int y,int &ans){
    if(!root){
        return NULL ;
    }
        ans=root->data;
    if(root->data==x || root->data==y){
        
        return root; 
    }
    TreeNode<int> * leftnode = solve(root->left,x,y,ans);
    TreeNode<int> * rightnode = solve(root->right,x,y,ans);
    if (leftnode && rightnode) {
        return root;
    }
    else if(leftnode!=NULL && rightnode==NULL){
        return leftnode;
    }

    else if(leftnode==NULL && rightnode!=NULL){
        return rightnode;
    }
    return NULL;


}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    int ans = 0;
    TreeNode<int>* temp = solve(root,x,y,ans);
    return temp->data;
}
