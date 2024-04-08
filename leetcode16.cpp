#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums={1,2,3,4};
    vector<int> ans={};
    int i,n,temp;
    n=nums.size();
    for(auto x:nums)
    {
        auto loc=find(nums.begin(),nums.end(),x);//find（）函数返回的值是一个指针
        printf("%d\n",*loc); //*loc是数组里的相对位置，而loc则是存储在数组中位置的存储地址
        printf("%d\n",loc);
        nums.erase(loc);
        temp=1;
        for(auto y:nums)
        {
            temp*=y;
        }
        ans.push_back(temp);
        nums.insert(loc,x);
    }
    for(auto z:ans)
    {
        cout<<z<<endl;
    }
}