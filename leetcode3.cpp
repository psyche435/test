#include<iostream>
#include<string>
#include<unordered_set>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    vector<int> nums={0,1};
    unordered_set<int> hashnum;
    for(auto x:nums)
    {
        hashnum.insert(x);
    }
    int i;
    int ans;
    ans=0;
    for(auto num:nums)
    {
        if(!hashnum.count(num-1))
        {
            int y=num;
            while(hashnum.count(y+1))
            {
                y++;
                cout<<y<<endl;
            }
            ans=max(ans,y-num+1);
        }
    }
    printf("%d",ans);
    return 0;
}