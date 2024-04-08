#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int n,i,j,k,a,ans,water;
    n=height.size();
    ans=0;
    int lMax[n]={0};
    int rMax[n]={0};
    int hwater[n]={0};
    lMax[0]=height[0];
    rMax[n-1]=height[n-1];
    for(i=1;i<n;i++)//起始位置是除去边界，终止位置必须包括，因为在定义时LMAX[0]，RMAX[N－1]是定义了，但另一个边界没有定义；
    {
        lMax[i]=max(height[i],lMax[i-1]);
    }
    for(j=n-1;j>=0;j--)
    {
        rMax[j]=max(height[j],rMax[j+1]);
    }
    for(k=0;k<n;k++)
    {
        hwater[k]=min(lMax[k],rMax[k]);
    }
    for(a=0;a<n;a++)
    {
        water=hwater[a]-height[a];
        ans+=water;
    }
    cout<<"the area of water is:"<<ans<<endl;
}