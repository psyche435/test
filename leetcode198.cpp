#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
int main()
{
    vector<int> nums={2,7,9,3,1};
    int n=nums.size();
    vector<int> memo(n,-1);
    function<int(int)> dfs = [&](int i)->int
    {
        if(i<0)
        {
            return 0;
        }
        if(memo[i]!=-1)
        {
            return memo[i];
        }
        return memo[i]=max(dfs(i-1),dfs(i-2)+nums[i]);
    };
    int ans;
    ans=dfs(n-1);
    cout<<ans<<endl;
}