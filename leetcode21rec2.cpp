#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=30;
    for(auto x:matrix)
    {
        auto a=lower_bound(x.begin(),x.end(),target);
        if(*a==target&&a!=x.end())
        {
            cout<<"true"<<endl;
            return 0;
        }
    }
    cout<<"false"<<endl;
}