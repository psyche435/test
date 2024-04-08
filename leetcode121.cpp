#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    vector<int> nums={7,6,4,3,1,2};
    unordered_map<int,int> umap;
    int n=nums.size();
    int minprice=1e9,maxprofit=0;
    for(int i=0;i<n;i++)
    {
        minprice=min(nums[i],minprice);
        maxprofit=max(nums[i]-minprice,maxprofit);
    }
    cout<<maxprofit;
}