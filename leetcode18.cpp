#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    int i,j,m,n;
    m=matrix.size();
    n=matrix[0].size();
    int h[m],l[n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(!matrix[i][j])
            {
                h[i]=l[j]=1;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(h[i]==1||l[j]==1)
            {
                matrix[i][j]=0;
                cout<<i<<j<<endl;
            }
        }
    }
    for(auto x:matrix)
    {
        for(auto y:x)
        {
            cout<<y<<'\t';
        }
        cout<<"\0"<<endl;
    }
}