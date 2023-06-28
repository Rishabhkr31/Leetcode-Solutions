class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});


        }
        vector<double>dist(n,0.00);
        vector<int>vis(n,0);
        queue<int>q;
        dist[start]=1.0;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                
                int node1=adj[node][i].first;
                if(vis[node1]==0){
                double v1=adj[node][i].second;
                double prob=v1*dist[node];
                if(prob>dist[node1]){
                    q.push(node1);
                    dist[node1]=prob;
                }
                }
            }
        }
        return dist[end];
        
    }
};