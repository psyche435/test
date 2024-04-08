#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
    unordered_map<int,int> unomap;
    vector<int> nums={1,1,1};
    int pre=0,count=0;
    int k=2;
    unomap[0]=1;
    for(auto x:nums)
    {
        pre+=x;
        if(unomap.find(pre-k)!=unomap.end())
        {
            count++;

        }
        unomap[pre]++;
    }
    cout<<count<<endl;
}