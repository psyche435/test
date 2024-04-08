#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    string s="aabcdaaaabcdea";
    vector<int> m(128,0);
    int i,head,maxlen;
    i=0;
    head=0;
    maxlen=0;
    for(i=0;i<s.size();i++)
    {
        head=max(head,m[s[i]]);/*head表示的是不重复字符串的起始位置.
        如果出现重复字母x,则m[x]的再赋值一定出现在head再赋值之后,此时head需要再赋值至m[x]的位置；
        如果没有出现重复字母x则m[x]的赋值一定是在head前面的，因为下一行指令才会对新字母进行m[x]
        的赋值，也正是下一条指令才会使m[x]的再赋值在head的后面，方便下一次判断*/
        m[s[i]]=i+1;//m[字母]的在赋值，始终代表不重复字母的最新位置（最新的字母排在第几个）
        maxlen=max(maxlen,i-head+1);
        //代表当前位置，head是不重复字符串的起始位置，则最大长度等于i-head+1
    }
    cout<<"the max no-repeat length is:"<<maxlen<<endl;
}