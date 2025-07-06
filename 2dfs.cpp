
  
  void dfs(int node,vector<int>&ans,vector<int>&visited,vector<vector<int>>& adj)
  {
      visited[node]=1;
      ans.push_back(node);
      for(auto &i:adj[node])
      {
          if(!visited[i])
          {
              dfs(i,ans,visited,adj); 
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> ans;
        vector<int> visited(n);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,ans,visited,adj);
            }
        }
        return ans;
        
    }
