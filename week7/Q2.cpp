class Solution {
public:
    void checkNearby(vector<vector<int>>& grid, int i, int j, queue<pair<int,int>>&q){
        int n=grid.size();
        int m=grid[0].size();
        if(i-1>=0){
            if(grid[i-1][j]==1){
                q.push({i-1,j});
                grid[i-1][j]=2;
            }
        }
        if(j-1>=0){
            if(grid[i][j-1]==1){
                q.push({i,j-1});
                grid[i][j-1]=2;
            }
        }
        if(i+1<n){
            if(grid[i+1][j]==1){
                q.push({i+1,j});
                grid[i+1][j]=2;
            }
        }
        if(j+1<m){
            if(grid[i][j+1]==1){
                q.push({i,j+1});
                grid[i][j+1]=2;
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
       int result=0;
        queue<pair<int,int>>q;
        //set<pair<int,int>>visited;
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(!fresh){
            return 0;
        }
        while(!q.empty()){
            int size=q.size();
            while(size>0){
                pair<int,int>coordinates=q.front();
                int i=coordinates.first;
                int j=coordinates.second;
                checkNearby(grid,i,j,q);
                q.pop();
                size--;
            }
            result++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return result-1;
    }
};
