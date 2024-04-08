#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    vector<vector<int>> grid={{2,1,1},{0,1,1},{1,0,1}};
    vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};//为什么要先上下后左右，并且更换顺序后输出结果会变
    int m=grid.size();
    int n=grid[0].size();
    int fresh=0;
    int ans=0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                fresh++;
            }
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        int l=q.size();
        bool f=false;
        for(int i=0;i<l;i++)
        {
            auto [x,y]=q.front();q.pop();
            for(auto s:dir)
            {
                int ni=s.first+x;
                int nj=s.second+y;
                if(ni<0||nj<0||ni==m||nj==n||grid[ni][nj]==2||grid[ni][nj]==0) continue;
                else
                    {
                        q.push({ni,nj});
                        grid[ni][nj]=2;
                        fresh--;
                        f=true;
                        for(auto a:grid)
                        {
                            for(auto b:a)
                            {
                                cout<<b;
                            }
                            cout<<endl;
                        }
                        cout<<ans<<' '<<f<<endl;
                        cout<<endl;
                    }
            }
        }
        if(f) ans++;
    }
    if(fresh>0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }
}