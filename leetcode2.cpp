#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<string>> ans;
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string,vector<string>> unomap;
    int i,j;
    for(auto &word:strs)
    {
        string key(word);
        sort(key.begin(),key.end());
        unomap[key].push_back(word);
    }
    for(auto &pair:unomap)
    {
        ans.push_back(pair.second);
    }
    for(auto a:ans)
    {    
        for(auto b:a)
        {
            cout<<b<<"\t";
        }
    cout<<"\n";
    }
    return 0;
}