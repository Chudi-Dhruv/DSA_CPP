#include <queue>
vector<int> bfsTraversal(int n, vector<vector<int>> &adj){

    vector<int> ans;
    vector<int> visited(n,0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    int vert = 0;
    while (q.empty() == false){
        vert = q.front();
        q.pop();
        ans.push_back(vert);
        for(int i=0;i<adj[vert].size();i++){
            int exp = adj[vert][i];
            if (visited[exp] == 0){
                q.push(exp);
                visited[exp] = 1;
            }
        }
    }

    return ans;
}
