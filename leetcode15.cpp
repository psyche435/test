#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    int k=3;
    vector<int> a={};
    int i,n;
    n=nums.size();
    for(i=0;i<n;i++)
    {
        a.push_back(nums[(i+n-k)%n]);
    }
    nums.assign(a.begin(),a.end());
    for(auto x:nums)
    {
        cout<<x<<endl;
    }
}