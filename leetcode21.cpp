#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;      //Z字查找
int main()
{
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int h=matrix.size();
    int l=matrix[0].size();
    int target=15;
    int i=h-1;
    int j=0;
    while(i>=0&&j<=l-1)
    {
        if(matrix[i][j]==target)
        {
            cout<<i<<'\t'<<j<<endl;
            break;
        }
        if(matrix[i][j]>target)
        {
            i--;
        }
        if(matrix[i][j]<target)
        {
            j++;
        }
    }
    return 0;
}