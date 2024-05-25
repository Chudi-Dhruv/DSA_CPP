int findCeil(BinaryTreeNode<int> *node, int x){

    // Write your code here.

    int ceil_value = -1;

    while(node != nullptr){

        if(node->data == x){

            return node->data;

        }

        else if(node->data < x){

            node = node->right;

        }

        else {

            ceil_value = node->data;

            node = node->left;   

        }

    }

 

    return ceil_value;

}
