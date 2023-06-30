class Solution {
public:
bool ispossible(int m,int n,int t,vector<vector<int>>&cells){
    vector<vector<int>>grid(m+1,vector<int>(n+1,0));
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(int i=0;i<t;i++){
        grid[cells[i][0]][cells[i][1]]=1;
    }
    queue<pair<int,int>>q;
      for (int i = 1; i <= n; i++) {
            if (grid[1][i] == 0) {
                q.push({1, i}); // Start BFS from the top row
                grid[1][i] = 1; // Mark the cell as visited
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first, c = p.second; // Current cell coordinates
            for (auto d : directions) {
                int nr = r + d.first, nc = c + d.second; // Neighbor cell coordinates
                if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; // Mark the neighbor cell as visited
                    if (nr == m) {
                        return true; // Found a path to the bottom row
                    }
                    q.push({nr, nc}); // Add the neighbor cell to the queue for further exploration
                }
            }
        }
        return false; // Unable to find a path to the bottom row
    



}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int left=0;
        int right=row*col;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(ispossible(row,col,mid,cells)){
                ans=mid;
                left=mid+1;
             
            }
            else{
                right=mid-1;
            }
        }
        return ans;
        
    }
};