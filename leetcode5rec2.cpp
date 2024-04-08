#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={1,8,6,2,5,4,8,3,7};
    int l,r,ans,area;
    l=0;
    ans=0;
    r=nums.size()-1;
    while(l<r)
    {
        area=(r-l)*min(nums[l],nums[r]);
        if(nums[l]<nums[r])
        {
            l++;
        }
        else
        {
            r--;
        }
        ans=max(ans,area);
    }
    cout<<ans<<endl;
    return 0;
}