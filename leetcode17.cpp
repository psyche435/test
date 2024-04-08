#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums={3,4,-1,1,2,7,8,9,11,12};
    int i=1;
    while(count(nums.begin(),nums.end(),i)!=0)
    {
        i++;
    }
    cout<<i<<endl;
}