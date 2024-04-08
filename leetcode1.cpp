#include<iostream>
#include<map>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums={3,3};
    int target=9;
    int i=0;
    map<int,vector<int>> vimap;
    vector<vector<int>> ans;
    for(auto x:nums)
    {
        vimap.emplace(x,i);
        i++;
    }
    cout<<vimap[3]<<endl;
    for(auto v:nums)
    {
        if(vimap.count(target-v)>0&&target-v!=v)
        {
            cout<<vimap[v]<<" "<<vimap[target-v]<<endl;
        }
    }
    return 0;
}