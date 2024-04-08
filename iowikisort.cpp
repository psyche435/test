#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selection_sort(vector<int>& nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int minx=i;//注意minx是用来标注当前最小值的角标
        for(int j=i+1;j<n;j++)
        {
            if(nums[minx]>nums[j])
            {
                minx=j;
            }
        }
        swap(nums[i],nums[minx]);//swap函数要在第一层循环里面，切勿放在第二层循环
    }
}
int main()
{
    vector<int> nums={9,5,6,4,2,1,3,8,7};
    selection_sort(nums);
    for(auto x:nums)
    {
        cout<<x<<endl;
    }
}