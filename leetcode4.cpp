#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums={0,1,0,3,12};
    int l,r,temp,n,wrongn;
    l=0;
    r=0;
    n=nums.size();
    wrongn=sizeof(nums);
    cout<<n<<endl;
    cout<<wrongn<<endl;
    while(r<n)
    {
        if(nums[r])
        {
            temp=nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
        }
        r++;
    }
    for(auto x:nums)
    {
        cout<<x<<" "<<endl;
    }
}