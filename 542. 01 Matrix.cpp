class Solution {
private:
    // void bfs(vector<vector<int>>& dup,int n,int m,int row,int col){
    //     int delrow[4]={-1,0,1,0};
    //     int delcol[4]={0,1,0,-1};
    //     int mini=0;
    //     for(int i=0;i<4;i++){
    //         int nrow=row+delrow[i];
    //         int ncol=col+delcol[i];
    //         if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
    //             mini=min(mini,dup[nrow][ncol]);

    //         }

    //     }
    //     dup[row][col]=mini+1;
        
    // }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0)) ;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else vis[i][j]=0;
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int newrow=q.front().first.first;
            int newcol= q.front().first.second;
            int dito=q.front().second;
            dis[newrow][newcol]=dito;

            q.pop();

            for(int i=0;i<4;i++){
                int nrow=newrow+delrow[i];
                int ncol=newcol+delcol[i];

                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m
                &&vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dito+1});

                }
            }
        }
        return dis;

    }
};
