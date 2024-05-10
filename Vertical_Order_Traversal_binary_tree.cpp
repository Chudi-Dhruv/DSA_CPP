#include<bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    queue<pair<TreeNode<int> *,pair<int,int>>> q;
    vector<int> ans;
    map<int,map<int,multiset<int>>> m;//here the first one is for the x cordinate
    //  and vector is for storing the values at that coordinate
    if(!root) return ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<TreeNode<int> *,pair<int,int>> temp_pair = q.front();
        q.pop();
        TreeNode<int> * temp = temp_pair.first;
        int hl,lev;
        hl=temp_pair.second.first;
        lev=temp_pair.second.second;
        if(temp->left){
            q.push(make_pair(temp->left,make_pair(hl-1,lev+1)));
        }
        if(temp->right){
            q.push(make_pair(temp->right,make_pair(hl+1,lev+1)));
        }
            m[hl][lev].insert(temp->data);
    }

    for(auto i:m){
        for(auto j:i.second){
            for (auto k : j.second) {
                ans.push_back(k);
            }
        }

    }

    return ans;
}
