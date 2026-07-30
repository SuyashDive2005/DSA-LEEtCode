class Solution {
public:
    void dfs(int currnode,vector<vector<int>> &adj,vector<bool>&visited){

        visited[currnode]=true;

        for(int &v:adj[currnode]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isconnected) {
        int n=isconnected.size();
        vector<vector<int>> adj(n);
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isconnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int prov=0;
        for(int i=0;i<n;i++){
            if(!visited[i]) {
                dfs(i,adj,visited);
                prov++;
            }
        }

        return prov;
    }
};