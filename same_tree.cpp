class Solution {
    bool solve(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        else if(p==NULL) return false;
        else if(q==NULL) return false;

        if(p->val!= q->val) return false;
        bool l,r;
        l = solve( p->left, q->left);
        r = solve( p->right, q->right);
        return l && r;
    }
    
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
