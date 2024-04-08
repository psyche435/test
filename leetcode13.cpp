#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    int pre=0;
    int maxans=nums[0];
    for(const auto &x:nums)
    {
        pre=max(pre+x,x);//注意这里的比较是pre＋x和x比较而不是和pre比较
        maxans=max(maxans,pre);
        cout<<maxans<<endl;
    }
    cout<<maxans<<endl;
}