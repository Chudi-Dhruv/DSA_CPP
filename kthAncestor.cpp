
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
Node* solve(Node *root, int &k, int node){
    if(!root) return NULL;

    if(root->data == node){
        return root;
    }
    Node* l = solve(root->left,k,node);
    Node* r = solve(root->right,k,node);
    if( l!= NULL && r==NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return l;
    }
    if( r!= NULL && l==NULL){
        k--;
        if(k<=0){
            k  = INT_MAX;
            return root;
        }
        return r;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    // Node* ans;
    // // bool flag = false
    // ans = solve(root,k,node);
    // if(ans ==NULL) return -1;
    // else return ans->data;
    Node* ans = solve(root,k,node);
    
    //if the answer is the node itself(for eg when k>levels in the tree)
    if(ans == NULL || ans->data == node){
        return -1;
    }
    
    else{
        return ans->data;
    }
    // Code here
}
