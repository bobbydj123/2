// Hehe bro
class Solution {
public:
     bool isSafe(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>>dist(row,vector<int>(col,-1));
        for(int i = 0;i<row;i++)
        {
            for(int j =0;j<col;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        //Now we will use multi-source bfs
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            for(auto& k:dir)
            {
                int x = p.first + k[0];
                int y = p.second + k[1];
                if(isSafe(x,y,row,col)&&dist[x][y]==-1)
                {
                    q.push({x,y});
                    dist[x][y] = dist[p.first][p.second]+1;
                }
            }
        }
        return dist;
    }
};
