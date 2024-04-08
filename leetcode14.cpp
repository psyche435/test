#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans;
    int i;
    for(i=0;i<intervals.size();i++)
    {
        sort(intervals.begin(),intervals.end());//sort()函数的格式：sort(vector.begin(),vector.end())
        int L=intervals[i][0],R=intervals[i][1];
        if(!ans.size()||ans.back()[1]<L)  //vector.back()指的是vector的第一层最后一个元素即{l,r},加个[1]即指的r
        {
            ans.push_back({L,R});//注意这里返回时要加｛ ｝
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],R);
        }
    }
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<"\t";
        }
        cout<<"\n"<<endl;
    }
}
//先将vector<vector<int>>的第一层按{l,r}中的l大小排序，这样相邻元素只要R1<L2,那就不可能有重复区间；