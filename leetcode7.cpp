#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={0,1,0,2,1,0,1,3,2,1,2,1};
    int i,j,l,r,n,m,a,b,area,ans,hwater;
    ans=0;
    n=nums.size();
    int llist[n];
    int rlist[n];
    for(i=1;i<n-1;i++)
    {
        if(nums[i-1]>nums[i]&&nums[i+1]>nums[i])
        {
            area=0;
            l=i-1;
            r=i+1;
            while(nums[l-1]>=nums[l]&&l!=0)
            {
                l--;
            }
            while(nums[r+1]>=nums[r]&&r!=n)
            {
                r++;
            }
            hwater=min(nums[l],nums[r]);
            cout<<l<<"\t"<<r<<endl;
            cout<<"the water height is:"<<hwater<<endl;
            for(j=l+1;j<r;j++)
            {
                area=area+(hwater-nums[j]);
                cout<<"the newly area is:"<<area<<endl;
            }
            ans+=area;
        }
    }
    cout<<ans<<endl;//此代码没有考虑一个水池包括两个低洼的情况，故示例1可以通过，但示例2答案错误；
}