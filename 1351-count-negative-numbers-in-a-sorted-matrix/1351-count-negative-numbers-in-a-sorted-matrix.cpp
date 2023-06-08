class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        int temp=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>=temp){
                    break;
                }
                if(grid[i][j]<0){
                    count+=(n-i)*(temp-j);
                    temp=j;
                    break;
                    
                }
            }
        }
        return count;
        
    }
};