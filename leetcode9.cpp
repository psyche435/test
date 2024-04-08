#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> m1(128,0);
    vector<int> m2(128,0);
    vector<int> ans;
    string s="abab";
    string p="ab";
    int i,j,k,f,a;
    int size1,size2;
    size1=s.size();
    size2=p.size();
    for(i=0;i<size2;i++)
    {
        m1[p[i]]+=1;
    }
    for(j=0;j<size1;j++)
    {
        for(auto &x:m2)
        {
            x=0;
        }
        for(k=0;k<size2;k++)
        {
            m2[s[j+k]]+=1;
        }
        bool result=equal(m1.begin(),m1.end(),m2.begin(),m2.end());
        if(result)
        {
            ans.push_back(j);
        }
    }
    for(auto a:ans)
    {
        cout<<a<<endl;
    }
}