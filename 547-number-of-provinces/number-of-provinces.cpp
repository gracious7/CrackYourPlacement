class Solution {
public:

    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;

        for(auto x: adj[node]){
            if(!vis[x]){
                dfs(x, adj, vis);
            }
        }

    }

    int findCircleNum(vector<vector<int>>& mat) {
        // int m = mat.size();//row
        // int n = mat[0].size();//col

        int n = mat.size();

        vector<vector<int>>adj(n);

        for(int i =0 ;i<n; i++){
            for(int j = 0; j< n; j++){
                if(mat[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int>vis(n, 0);

        // queue<int>q;
        // q.push(0);
        // vis[0] = 1;

        int cnt = 0;//it will count how many times bfs is called
        for(int i = 0; i<n; i++){

            if(vis[i] == 0){
                dfs(i, adj, vis);
                cnt++;
            }

        }

        return cnt;








    }
};