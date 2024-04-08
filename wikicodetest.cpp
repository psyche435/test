#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct f
{
    long long d;
    long long p;
};
bool cmp(f s1,f s2)
{
    return(s1.d>s2.d);
};
int main()
{
    priority_queue<long long,vector<long long>,greater<long long>> q;
    int n,ans=0;
    cin>>n;
    f a[10005];
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld",&a[i].d,&a[i].p);
    }
    sort(a+1,a+n+1,cmp);
    for(int j=0;j<n;j++)
    {
        if(a[j].d<q.size())
        {
            if(q.top()<a[j].p)
            {
                ans=ans+a[j].p-q.top();
                q.pop();
                q.push(a[j].p);
            }
        }
        else
        {
            ans+=a[j].p;
            q.push(a[j].p);
        }
    }
    cout<<ans<<endl;
}