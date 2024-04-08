#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={1,8,6,2,5,4,8,3,7};
    unordered_map<int,int> unomap;
    int i=0;
    int r,c,length,height,ans;
    ans=-1;
    int n=nums.size();
    cout<<n<<endl;
    for(auto x:nums)
    {
        unomap.emplace(i,x);
        cout<<unomap[i]<<"\t";
        i++;
    }
    cout<<"\n";
    int dp[n][n]={0};
    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            length=abs(r-c);
            height=min(unomap[r],unomap[c]);
            dp[r][c]=length*height;
            cout<<dp[r][c]<<"\t";
            ans=max(ans,dp[r][c]);
        }
        cout<<"\n";
    }
    cout<<ans;
}