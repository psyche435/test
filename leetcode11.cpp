#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
int main()
{
    vector<int> nums={9,10,9,-7,-4,-8,2,-6};
    priority_queue<pair<int,int>> window;
    int n=nums.size();
    int k=5;
    int i,j;
    for(i=0;i<k;i++)
    {
        window.emplace(nums[i],i);
    }
    vector<int> ans={window.top().first};
    for(j=k;j<n;j++)
    {
        window.emplace(nums[j],j);
        if(window.top().second<=j-k)
        {
            window.pop();
        }
        ans.push_back(window.top().first);
    }
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
}