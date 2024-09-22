//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool check(int i,int j,int m, int n, vector<vector<int>>& grid)
    {
        if (i == m or j == n or i == -1 or j == -1)
          return false;
        if (grid[i][j] == 0)
          return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        queue<pair <pair<int,int>, int>> qq;
        int vis[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (grid[i][j] == 2)
                {
                    qq.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else
                vis[i][j] = 0;
            }
        }
        int ti = 0;
        while(!qq.empty())
        {
            int r = qq.front().first.first;
            int c = qq.front().first.second;
            int t = qq.front().second;
            
            qq.pop();
            // i-1,j
            if(check(r-1,c,m,n,grid))
            {
                if(vis[r-1][c] != 2)
                {
                    qq.push({{r-1,c},t+1});
                    vis[r-1][c] = 2;
                }
                  
            }
            //i+1,j
            if(check(r+1,c,m,n,grid))
            {
                if(vis[r+1][c] != 2)
                {
                    qq.push({{r+1,c},t+1});
                    vis[r+1][c] = 2;
                }
                  
            }            
            //i,j-1
            if(check(r,c-1,m,n,grid))
            {
                if(vis[r][c-1] != 2)
                {
                    qq.push({{r,c-1},t+1});
                    vis[r][c-1] = 2;
                }
                  
            }            
            //i,j+1
            if(check(r,c+1,m,n,grid))
            {
                if(vis[r][c+1] != 2)
                {
                    qq.push({{r,c+1},t+1});
                    vis[r][c+1] = 2;
                }
                  
            }
            ti = max(t,ti);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (grid[i][j] == 1 and vis[i][j]!=2)
                {
                    return -1;
                }
            }
        }
        return ti;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
