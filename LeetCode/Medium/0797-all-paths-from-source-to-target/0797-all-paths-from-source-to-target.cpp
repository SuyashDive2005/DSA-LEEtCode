class Solution {
public:
    void dfs(int currnode,int source,int destination,vector<vector<int>>&adj,vector<bool>&visited,vector<int> &path,vector<vector<int>>& allpaths){

        visited[currnode]=true;

        if(currnode==destination){
            allpaths.push_back(path);
        }

        for(auto& v:adj[currnode]){
            path.push_back(v);
            if(!visited[v]){
                dfs(v,source,destination,adj,visited,path,allpaths);
                visited[v]=false;
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> allpaths;
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<int> path={0};

        dfs(0,0,n-1,graph,visited,path,allpaths);

        return allpaths;
    }
};