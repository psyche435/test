#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={-1,0,1,2,-1,-4};
    sort(nums.begin(),nums.end());
    int i,l,r,n,sum1;
    n=nums.size();
    cout<<n<<endl;
    for(auto x:nums)
    {
        cout<<x<<endl;
    }
    for(i=0;i<n;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            sum1=nums[i]+nums[l]+nums[r];
            cout<<"sum:"<<sum1<<endl;
            if(sum1>0)
            {
                r--;
                cout<<"r->:"<<r<<endl;
            }
            else if(sum1<0)
            {
                l++;
                cout<<"l->:"<<l<<endl;
            }
            else
            {
                cout<<"the three number,that sum=0: "<<nums[i]<<","<<nums[l]<<","<<nums[r]<<"\t"<<endl;
                break;
            }
        }
    }
    return 0;
}