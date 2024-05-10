
vector<int> diagonalTraversal(TreeNode<int> *root) {

    vector<int> ans;
    if(!root) return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    // map<int, 
    while(!q.empty()){
        TreeNode<int> * temp =q.front();
        q.pop();
        while(temp){
            if(temp->left) q.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }
    }
    return ans;
    // Write your code here.
}
